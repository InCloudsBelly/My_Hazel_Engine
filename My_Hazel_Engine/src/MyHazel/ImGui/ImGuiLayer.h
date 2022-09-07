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
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}