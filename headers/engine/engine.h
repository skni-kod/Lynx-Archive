#pragma once
#include <Application/Abstract/AbstractApplication.h>

class __declspec(dllexport) CEngine
{
public:
	AbstractApplication* platformApp;

	void Init();
	void Run();
};