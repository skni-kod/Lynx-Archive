#include <iostream>
#include "engine.h"

#include "renderer/renderer.h"

int __declspec(dllexport) __cdecl dupa() {
    test();
	return 0xf;
}

void __declspec(dllexport) __cdecl update()
{
	//Do something
    int x = 0;
    x++;
}
