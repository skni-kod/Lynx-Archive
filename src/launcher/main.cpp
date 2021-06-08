#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <engine.h>
#include <windows.h>
#include <gl/GL.h>
#include "launcher.h"
#include <io.h>
#include <fcntl.h>


#pragma comment (lib, "opengl32.lib")

HGLRC GLContext;

HDC WinHandleDC;

typedef int(__stdcall* update_f)();

typedef void(__stdcall* func_f)();


void DrawTriangle()
{
    glIndexi(1);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(0, 1);
    glIndexi(2);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(-1, -1);
    glIndexi(3);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(1, -1);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    LRESULT Result = 0;
    // Message handling
    static PAINTSTRUCT ps;
    switch (uMsg) {
    case WM_CREATE:
    {
        break;
    }
    case WM_DESTROY: {
        wglDeleteContext(GLContext);
        PostQuitMessage(0);
    } break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);    // Closing Window
    } break;
    case WM_PAINT: {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        //All drawing should be done here most likely.
        DrawTriangle();
        
        //End current draw frame.
        glEnd();
        //Flush accumulated commands, so we can end our frame.
        glFlush();
        //Swap buffers.
        SwapBuffers(WinHandleDC);
        BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
    } break;
    case WM_SIZE: {
        glViewport(0, 0, LOWORD(lParam), HIWORD(lParam)); //Setup viewport to new size.
        PostMessage(hwnd, WM_PAINT, 0, 0);
    }
    default: {
        Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    } break;
    }
    return Result;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    AllocConsole();
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;
    
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);

    //load update and render loops?
    HINSTANCE hGetProcIDDLL = LoadLibrary("Engine.dll");
    
    update_f update = (update_f)GetProcAddress(hGetProcIDDLL, "update");
//    func_f func = (func_f)GetProcAddress(hGetProcIDDLL, "dupa");
//
//    if(!func)
//        exit(-1);
//    func();

    // Register the window class
    WNDCLASS WindowClass = {};

    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = hInstance;
    WindowClass.lpszClassName = "LynxEngineClass";

    // Create the window.
    RegisterClass(&WindowClass);

    HWND WindowHandle = CreateWindowExA(
        0,                                       // Optional Window styles
        WindowClass.lpszClassName,               // Window Class
        WINDOW_TITLE,                           // Window text
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,          // Window Style
        CW_USEDEFAULT,                           // Pos X
        CW_USEDEFAULT,                           // Pos Y
        CW_USEDEFAULT,                           // Width
        CW_USEDEFAULT,                           // Height
        0,                                        // Parent Window
        0,                                // Menu
        hInstance,                               // Instance Handle
        0                                // Additional application data
    );

    //TEST OPENGL
            //TODO think about how to support DirectX AND OpenGL at the same time. For now focus on OpenGL.

        //Create pixel format descriptor.
    PIXELFORMATDESCRIPTOR pfd{
                    sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
        PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
        32,                   // Colordepth of the framebuffer.
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24,                   // Number of bits for the depthbuffer
        8,                    // Number of bits for the stencilbuffer
        0,                    // Number of Aux buffers in the framebuffer.
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    //Get Device Context (DC) for specified window.
    WinHandleDC = GetDC(WindowHandle);
    //Find pixel format closest to one we described in pfd
    int pfIndex = ChoosePixelFormat(WinHandleDC, &pfd);
    //Set DCs' pixel format in at pfIndex to our pfd.
    SetPixelFormat(WinHandleDC, pfIndex, &pfd);
    //Create OpenGL context for given window.
    GLContext = wglCreateContext(WinHandleDC);
    //Sets created openGL context as current.
    wglMakeCurrent(WinHandleDC, GLContext);
    //TODO (Minus) figure out why GL_VERSION define isn't working
    //MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    ShowWindow(WindowHandle, SW_SHOW);
    UpdateWindow(WindowHandle);

    // Message Procedure
    if (WindowHandle)
    {
        MSG msg;
        while (TRUE)
        {
            while (PeekMessage(&msg, WindowHandle, 0, 0, PM_NOREMOVE))
            {
                if (GetMessage(&msg, WindowHandle, 0, 0))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                else {
                    goto quit;
                }
            }
            //Call Engine and game code here
            update();

        }
    }

//TODO Reconsider how it should be done properly.
quit:
    return 0;
}