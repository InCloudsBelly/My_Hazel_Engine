#pragma once
#include "Core.h"
#include "Window.h";
#include "LayerStack.h"
#include "Events/Event.h"
#include"MyHazel/Events/ApplicationEvent.h"
#include "MyHazel/ImGui/ImGuiLayer.h"


namespace MyHazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindiwClosed(WindowClosedEvent & e);


		ImGuiLayer * m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();

}

