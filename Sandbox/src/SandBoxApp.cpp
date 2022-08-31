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

		if (MyHazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_INFO("Tab key is pressed!(poll)");

		//HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(MyHazel::Event& event) override
	{
		if (event.GetEventType() == MyHazel::EventType::KeyPressed)
		{
			MyHazel::KeyPressedEvent& e = (MyHazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("Tab key is pressed!(event)!");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
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