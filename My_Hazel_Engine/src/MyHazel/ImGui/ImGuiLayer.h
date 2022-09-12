#pragma once

#include "MyHazel/Core/Layer.h"
#include "MyHazel/Events/KeyEvent.h"
#include "MyHazel/Events/MouseEvent.h"
#include "MyHazel/Events/ApplicationEvent.h"

namespace MyHazel {

	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:

		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}