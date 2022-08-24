#include <MyHazel.h>

class Sandbox : public MyHazel::Application {
public:
	Sandbox() {
	
	}

	~Sandbox() {
	
	}

};

MyHazel::Application* MyHazel::CreateApplication() 
{
	return new Sandbox();
}