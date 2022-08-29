#include <MyHazel.h>

class ExampleLayer :public MyHazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate()override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(MyHazel::Event& event) override
	{
		HZ_TRACE("{0}",event);
	}

};

class Sandbox : public MyHazel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {
	
	}

};

MyHazel::Application* MyHazel::CreateApplication() 
{
	return new Sandbox();
}