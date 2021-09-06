#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include <xcb/xcb.h>

#include <X11/Xlib.h>


/*
  To use it on windows 10 wsl you need to install:
  X's server for windows eg: https://sourceforge.net/projects/xming/
  in wsl shell where you run program, execute that command:
  export DISPLAY=:0
  and before start you need to open X's server session on your computer!
*/

double
get_time(void)
{
  struct timeval timev;

  gettimeofday(&timev, NULL);

  return (double)timev.tv_sec + (((double)timev.tv_usec) / 1000000);
}

int main()
{
  xcb_connection_t *c;
  xcb_atom_t *atoms;
  xcb_intern_atom_cookie_t *cs;
  char **names;
  int count;
  int i;
  double start;
  double end;
  double diff;

  /* Xlib */
  Display *disp;
  Atom *atoms_x;
  double diff_x;

  c = xcb_connect(NULL, NULL);

  count = 500;
  atoms = (xcb_atom_t *)malloc(count * sizeof(atoms));
  names = (char **)malloc(count * sizeof(char *));

  /* init names */
  for (i = 0; i < count; ++i)
  {
    char buf[100];

    sprintf(buf, "NAME%d", i);
    names[i] = strdup(buf);
  }

  /* bad use */
  start = get_time();

  for (i = 0; i < count; ++i)
    atoms[i] = xcb_intern_atom_reply(c,
                                     xcb_intern_atom(c,
                                                     0,
                                                     strlen(names[i]),
                                                     names[i]),
                                     NULL)
                   ->atom;

  end = get_time();
  diff = end - start;
  printf("bad use time  : %f\n", diff);

  /* good use */
  start = get_time();

  cs = (xcb_intern_atom_cookie_t *)malloc(count * sizeof(xcb_intern_atom_cookie_t));
  for (i = 0; i < count; ++i)
    cs[i] = xcb_intern_atom(c, 0, strlen(names[i]), names[i]);

  for (i = 0; i < count; ++i)
  {
    xcb_intern_atom_reply_t *r;

    r = xcb_intern_atom_reply(c, cs[i], 0);
    if (r)
      atoms[i] = r->atom;
    free(r);
  }

  end = get_time();
  printf("good use time : %f\n", end - start);
  printf("ratio         : %f\n", diff / (end - start));
  diff = end - start;

  /* free var */
  free(atoms);
  free(cs);

  xcb_disconnect(c);

  /* Xlib */
  disp = XOpenDisplay(getenv("DISPLAY"));

  atoms_x = (Atom *)malloc(count * sizeof(atoms_x));

  start = get_time();

  for (i = 0; i < count; ++i)
    atoms_x[i] = XInternAtom(disp, names[i], 0);

  end = get_time();
  diff_x = end - start;
  printf("Xlib use time : %f\n", diff_x);
  printf("ratio         : %f\n", diff_x / diff);

  free(atoms_x);
  for (i = 0; i < count; ++i)
    free(names[i]);
  free(names);

  XCloseDisplay(disp);

  return 0;
}