#include <iostream>
#include "engine.h"
#include <stb_image.h>

FILE test1;
void* test = stbi_load_from_file(&test1, (int*)4,(int*)3,(int*)4, 3);
