#pragma once

#include "MyHazel/Core/Base.h"
#include "MyHazel/Core/Timestep.h"
#include "MyHazel/Events/Event.h"

namespace MyHazel {
	
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};
}