#pragma once
#include "MyHazel/Core/Base.h"
#include "MyHazel/Core/KeyCodes.h"
#include "MyHazel/Core/MouseCodes.h"

namespace MyHazel {
		
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}