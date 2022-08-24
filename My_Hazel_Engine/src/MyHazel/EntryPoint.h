#pragma once
#ifdef HZ_PLATFORM_WINDOWS

extern MyHazel::Application* MyHazel::CreateApplication();

int main(int argc, char ** argv) 
{
	auto app = MyHazel::CreateApplication();
	app->Run();
	delete app;
}

#endif