#include <MyHazel.h>
#include "MyHazel/Core/EntryPoint.h"

#include "Sandbox2D.h"


class Sandbox : public MyHazel::Application {
public:
	Sandbox() {
		PushLayer(new Sandbox2D());

	}

	~Sandbox() {
	
	}

};

MyHazel::Application* MyHazel::CreateApplication() 
{
	return new Sandbox();
}