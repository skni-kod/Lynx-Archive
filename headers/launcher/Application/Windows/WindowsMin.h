#pragma once

//Prevent loading of rarely used functions and services from WinAPI
#define WIN32_LEAN_AND_MEAN

//If we don't need something from WinAPI we should define here what we're not going to use.

#include <Windows.h>

#include <io.h>
#include <fcntl.h>
#include <cstdio>