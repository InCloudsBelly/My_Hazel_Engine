#include "Application.h"

#include"MyHazel/Events/ApplicationEvent.h"
#include"MyHazel/Log.h"

namespace MyHazel{
	
	Application::Application() 
	{
	
	}

	Application::~Application() 
	{
	
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		HZ_TRACE(e);
		while (true);
	}

}