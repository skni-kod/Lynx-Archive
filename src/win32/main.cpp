#include <windows.h>
#include <iostream>
#include <engine.h>
#include <windows.h>
#include "launcher.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    LRESULT Result = 0;
    // Message handling
    switch (uMsg) {
    case WM_DESTROY: {
        PostQuitMessage(0);
    } break;

    case WM_CLOSE: {
        DestroyWindow(hwnd);    // Closing Window
    } break;

    case WM_PAINT: {

        PAINTSTRUCT PaintStruct;
        HDC hdc = BeginPaint(hwnd, &PaintStruct);

        FillRect(hdc, &PaintStruct.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &PaintStruct);
    } break;

    default: {
        Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    } break;
    }
    return Result;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {

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

    // Message Procedure
    if (WindowHandle) {
        while (TRUE) {
            MSG Message;
            if (GetMessage(&Message, nullptr, 0, 0) > 0) {
                TranslateMessage(&Message);
                DispatchMessage(&Message);
            }
            else {
                break;
            }
        }
    }
    return 0;
}

/*
DLL loading
#include <windows.h>
#include <iostream>

Define a function pointer for our imported
 * function.
 * This reads as "introduce the new type f_funci as the type:
 *                pointer to a function returning an int and
 *                taking no arguments.
 *
 * Make sure to use matching calling convention (__cdecl, __stdcall, ...)
 * with the exported function. __stdcall is the convention used by the WinAPI

typedef int(__stdcall* f_funci)();

int main()
{
    HINSTANCE hGetProcIDDLL = LoadLibrary("Engine.dll");

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return EXIT_FAILURE;
    }

    // resolve function address here
    f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, "dupa");
    if (!funci) {
        std::cout << "could not locate the function" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "funci() returned " << funci() << std::endl;

    return EXIT_SUCCESS;
}
*/