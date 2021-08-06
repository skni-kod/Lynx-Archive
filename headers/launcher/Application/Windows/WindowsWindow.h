#pragma once

#include "Application/Abstract/AbstractWindow.h"
#include "Application/Windows/WindowsMin.h"

class __declspec(dllexport) WindowsWindow : public AbstractWindow
{
public:
	static const char* WinAppWndClassName;
	
	//Normally I'd use public value, but we don't want to ever change that value.
	HWND GetHWND() const;
	
	//Platform specific functions
	//TODO figure out list of params needed to init window, and link it with some kinds of App class.
	void Initialize(int w, int h, HINSTANCE* hInstance);

	//AbstractWindow interface
	//TODO figure out fullscreen mode


	//TODO(Minus): Document this shit ton of functions for windows.
	virtual void SetPosition(int32 x, int32 y) override;
	virtual void Minimalize() override;
	virtual void Maximalize() override;
	virtual void ChangeSize() override;
	virtual void Restore() override;
	virtual void Show() override;
	virtual void Hide() override;
	virtual bool IsMaximized() const override;
	virtual bool isMinimized() const override;
	virtual void SetWindowFocus() override;

	WindowsWindow();

private:
	HWND HWnd;
};