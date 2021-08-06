#include "Application/Windows/WindowsApplication.h"

#include <iostream>

WindowsApplication* winAppPtr = nullptr;

WindowsApplication::WindowsApplication(const HINSTANCE hInstance, const HICON iconHandle) :
   Windows(), hInstance(hInstance)
{
    winAppPtr = this;
}

signed int WindowsApplication::ProcessMessage(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
    //THIS SWITCH WILL BE HUGE, REMEMBER THAT!!!
    switch (msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        } 

        case WM_CLOSE:
        {
            DestroyWindow(hwnd);    // Closing Window
            return 0;
        } 

        case WM_PAINT:
        {
            static PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        } 
        case WM_SIZE:
        {
            PostMessage(hwnd, WM_PAINT, 0, 0);
            return 0;
        }
        default:
            break;
            //TODO think if we need to do something about other messages before we send them to DefWindowProc.
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

bool WindowsApplication::RegisterWindowClass(const HINSTANCE hInstance, const HICON hIcon)
{
    WNDCLASSEX wc = {};

    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc = WinAppWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hIconSm = wc.hIcon;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = WindowsWindow::WinAppWndClassName;
    wc.cbSize = sizeof(WNDCLASSEX);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, TEXT("Window Class Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    return true;
}

LRESULT WindowsApplication::WinAppWndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
    return winAppPtr->ProcessMessage(hwnd, msg, wParam, lParam);
}

void WindowsApplication::Update()
{
    printf("DUPA\n");
}

AbstractWindow* WindowsApplication::MakeWindow()
{
    return new WindowsWindow;
}

void WindowsApplication::InitWindow(AbstractWindow* window, uint32 x, uint32 y, uint32 w, uint32 h, bool maximalized, bool fullscreen, bool show_immediately)
{
    WindowsWindow* Win32WindowPtr = (WindowsWindow*)window;
    Win32WindowPtr->Initialize(w, h, &hInstance);
}

void WindowsApplication::MainLoop()
{
    while (1)
    {
        Update();

        
        //That's how windows does things, this is experimental only here.
        // It will be changed to generic method that should be implemented in other platform.
        MSG Message;

        // standard Windows message handling
        while (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
    }
}
