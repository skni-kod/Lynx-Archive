#pragma once

#include "Core/BaseTypes.h"
#include "Application/Abstract/AbstractWindow.h"

//Abstract platform application code
class AbstractApplication
{
public:
	//TODO(Minus): These methods need documentation, base it on WindowsApplication class, but firstly create all things required.
	virtual void Update() = 0;
	//TODO add WindowDef class or consider what options are required)
	virtual AbstractWindow* MakeWindow() { return new AbstractWindow(); }
	virtual void InitWindow(AbstractWindow* window, uint32 x, uint32 y, uint32 w, uint32 h, bool maximalized = false, bool fullscreen = false, bool show_immediately = false) { }
	virtual void MainLoop() { }
};