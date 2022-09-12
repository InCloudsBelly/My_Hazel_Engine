#include <MyHazel.h>
#include <MyHazel/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MyHazel {
	
	class Engine_Editor : public Application
	{
	public:
		Engine_Editor()
			:Application("Hazel Editor")
		{
			PushLayer(new EditorLayer());
		}

		~Engine_Editor()
		{

		}

	};

	Application* CreateApplication()
	{
		return new Engine_Editor();
	}
}