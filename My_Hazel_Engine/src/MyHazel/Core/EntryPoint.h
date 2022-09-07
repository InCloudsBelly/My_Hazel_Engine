#pragma once
#include "MyHazel/Core/Core.h"

#ifdef HZ_PLATFORM_WINDOWS

extern MyHazel::Application* MyHazel::CreateApplication();

int main(int argc, char ** argv) 
{
	MyHazel::Log::Init();
	
	HZ_CORE_WARN("Initialized Log !");
	int a = 5;
	HZ_INFO("Hello! Var={0}",a);

	auto app = MyHazel::CreateApplication();
	app->Run();
	delete app;
}

#endif