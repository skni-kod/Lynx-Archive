#pragma once
#include "Application/Abstract/AbstractApplication.h"
#include "Application/Windows/WindowsMin.h"

#include <vector>
#include <Application/Windows/WindowsWindow.h>

//@todo Consider defining __declspec(dllexport) as DLLEXPORT or something similar for other platforms to use properly.
class WindowsApplication : public AbstractApplication
{	
public:
	/** WindowsApplication constructor*/
	WindowsApplication(const HINSTANCE hInstance, const HICON iconHandle);

//protected:
	/** 
	* Process Windows message
	*/
	int32 ProcessMessage(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);

	/**
	* Register Win32 Window Class for WindowsApplication to create native windows.
	* @param hInstance instance of a Win32 Process we're creating.
	* @param hIcon icon of application shown on window.
	* @return True if window was created, false when there was an error creating window.
	*/
	bool RegisterWindowClass(const HINSTANCE hInstance, const HICON hIcon);

	/**
	* Callback for all window instances used to process received messages (events).
	* This method is static due to limitations of WinAPI, that's why it is calling another method,
	* which can identify it's own window and process it's messages accordingly.
	* @param hwnd handle to the window which received given event.
	* @param msg message that was sent (event)
	* @param wParam additional parameter sent with message
	* @param lParam additional parameter sent with message
	* @see ProcessMessage()
	* @return call for instantiated ProcessMessage
	*/
	static LRESULT CALLBACK WinAppWndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);

	virtual void Update() override;

	/**
	* Dynamic array containing all windows we created.
	*/
	std::vector<WindowsWindow*> Windows;

	/**
	* Implemented MakeWindow from AbstractApplication.
	*/
	virtual AbstractWindow* MakeWindow() override;

	/**
	* Implemented InitWindow from AbstractApplication
	* @see AbstractApplication#InitWindow()
	*/
	virtual void InitWindow(AbstractWindow* window, uint32 x, uint32 y, uint32 w, uint32 h, bool maximalized = false, bool fullscreen = false, bool show_immediately = false) override;

	//TODO Should main loop be called from platform or be held entirely withing Engine library
	virtual void MainLoop() override;

	HINSTANCE hInstance;
};