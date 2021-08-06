#include "engine.h"

void CEngine::Init()
{
	//TODO (Minus): Add some kind of list of windows created for App. For now limit creation of windows to this one.
	// 	   THIS IS MEMORY LEAK SITUATION, WE'RE LOOSING POINTER TO CREATED WINDOW.
	AbstractWindow* win = platformApp->MakeWindow();
	platformApp->InitWindow(win, 0, 0, 1280, 720);
}


void CEngine::Run()
{
	Init();
	
	platformApp->MainLoop();

	//TODO add Cleanup and exit routines
	//Properly understand cleanup things, if we're exiting program we're not really required to completely cleanup everything, since OS should clean after us.
	//Cleanup should be used properly eg. when exiting thread, but continuing work of application.
}
