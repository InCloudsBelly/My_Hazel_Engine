#pragma once
#include "MyHazel/Core/Core.h"
#include "Window.h"
#include "LayerStack.h"

#include "MyHazel/Events/Event.h"
#include "MyHazel/Events/ApplicationEvent.h"
#include "MyHazel/Core/Timestep.h"

#include "MyHazel/ImGui/ImGuiLayer.h"

#include "MyHazel/Renderer/VertexArray.h"
#include "MyHazel/Renderer/Shader.h"
#include "MyHazel/Renderer/Buffer.h"
#include "MyHazel/Renderer/OrthographicCamera.h"


namespace MyHazel {

	class Application
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
		bool OnWindiwResized(WindowResizedEvent& e);

		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true, m_Minimized = false;
		LayerStack m_LayerStack;

		Timestep m_Timestep;
		float m_LastFrameTime;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();

}

