#include "Application/Windows/WindowsMin.h"

#include "Application/Windows/WindowsWindow.h"
#include "Application/Windows/WindowsApplication.h"

#include "engine.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow)
{
//Allocating and opening console for debug builds
#ifdef DEBUG_BUILD
    //Allocate console
    AllocConsole();
    //Get WinAPI handle for STD_OUTPUT
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    //Open "file" of STD_OUT handle
    int hCrt = _open_osfhandle((intptr_t)handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    //Same stuff, but for STD_IN
    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((intptr_t)handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    // reopen stadard in and out, to attach them to our console.
    // Also stupid workaround for C6031 warning.
    void* foo;
    foo = (void*)freopen("CONOUT$", "w", stdout);
    foo = (void*)freopen("CONIN$", "r", stdin);
#endif
//End of console

    // This is basically all code required to launch Engine Runtime Environment.
    // When time comes there should be more and more stuff added before or after these methods.
    // Other platforms should use something similar for launching.
    CEngine* engine = new CEngine();
    WindowsApplication* winApp = new WindowsApplication(hInstance, nullptr);
    // Maybe make this less confusing / launch proper platform code from engine "main" and not platform specific one.
    engine->platformApp = (AbstractApplication*)winApp;
    winApp->RegisterWindowClass(hInstance, nullptr);
    engine->Run();

    return 0;
}