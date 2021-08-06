#include "Application\Windows\WindowsWindow.h"

const char* WindowsWindow::WinAppWndClassName = "LynxEngineWindowClass";

HWND WindowsWindow::GetHWND() const
{
	return HWnd;
}

void WindowsWindow::Initialize(int w, int h, HINSTANCE* hInstance)
{
    HWnd = NULL;
    HWnd = CreateWindowExA(
        0,                                       // Optional Window styles
        WindowsWindow::WinAppWndClassName,               // Window Class
        "Lynx Engine - Dev",                           // Window text
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,          // Window Style
        CW_USEDEFAULT,                           // Pos X
        CW_USEDEFAULT,                           // Pos Y
        CW_USEDEFAULT,                           // Width
        CW_USEDEFAULT,                           // Height
        0,                                        // Parent Window
        0,                                // Menu
        *hInstance,                               // Instance Handle
        0                                // Additional application data
    );
    if (HWnd)
    {
        ShowWindow(HWnd, SW_SHOW);
        UpdateWindow(HWnd);
    }
}

//Any other platform should implement this functionality by moving window to given coordinates in screen space and retaining window size.
void WindowsWindow::SetPosition(int32 x, int32 y)
{
	// SetWindowPos from WinAPI, check FLAGS param in WinAPI docs.
    // SWP_NOSIZE - we're not giving new size for window.
    // SWP_NOACTIVATE - Window won't be set as active if it was inactive.
    // SWP_NOZORDER - Do not change Z order of window in DWM. Ignores hWndInsertAfter param.
    SetWindowPos(HWnd, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOZORDER);
}

void WindowsWindow::Minimalize()
{
	ShowWindow(HWnd, SW_MINIMIZE);
}

void WindowsWindow::Maximalize()
{
	ShowWindow(HWnd, SW_MAXIMIZE);
}

void WindowsWindow::ChangeSize()
{
	throw;
}

void WindowsWindow::Restore()
{
	throw;
}

void WindowsWindow::Show()
{
    ShowWindow(HWnd, SW_SHOW);
}

void WindowsWindow::Hide()
{
    ShowWindow(HWnd, SW_HIDE);
}

bool WindowsWindow::IsMaximized() const
{
	return false;
}

bool WindowsWindow::isMinimized() const
{
	return false;
}

void WindowsWindow::SetWindowFocus()
{
	throw;
}

WindowsWindow::WindowsWindow() :
    HWnd(nullptr)
{
}
