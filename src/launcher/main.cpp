#include <windows.h>
#include <iostream>
#include <engine.h>
#include <stb_image.h>


typedef int(__stdcall* f_funci)();

int main()
{
    HINSTANCE hGetProcIDDLL = LoadLibrary("Test_dll.dll");

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return EXIT_FAILURE;
    }

    // resolve function address here
    f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, "testFunc");
    if (!funci) {
        std::cout << "could not locate the function" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "funci() returned " << funci() << std::endl;

    return EXIT_SUCCESS;
}