#pragma once

namespace MyHazel
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define HZ_MOUSE_BUTTON_0      ::MyHazel::Mouse::Button0
#define HZ_MOUSE_BUTTON_1      ::MyHazel::Mouse::Button1
#define HZ_MOUSE_BUTTON_2      ::MyHazel::Mouse::Button2
#define HZ_MOUSE_BUTTON_3      ::MyHazel::Mouse::Button3
#define HZ_MOUSE_BUTTON_4      ::MyHazel::Mouse::Button4
#define HZ_MOUSE_BUTTON_5      ::MyHazel::Mouse::Button5
#define HZ_MOUSE_BUTTON_6      ::MyHazel::Mouse::Button6
#define HZ_MOUSE_BUTTON_7      ::MyHazel::Mouse::Button7
#define HZ_MOUSE_BUTTON_LAST   ::MyHazel::Mouse::ButtonLast
#define HZ_MOUSE_BUTTON_LEFT   ::MyHazel::Mouse::ButtonLeft
#define HZ_MOUSE_BUTTON_RIGHT  ::MyHazel::Mouse::ButtonRight
#define HZ_MOUSE_BUTTON_MIDDLE ::MyHazel::Mouse::ButtonMiddle3