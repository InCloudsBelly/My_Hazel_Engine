#pragma once
namespace MyHazel
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define HZ_KEY_SPACE           ::MyHazel::Key::Space
#define HZ_KEY_APOSTROPHE      ::MyHazel::Key::Apostrophe    /* ' */
#define HZ_KEY_COMMA           ::MyHazel::Key::Comma         /* , */
#define HZ_KEY_MINUS           ::MyHazel::Key::Minus         /* - */
#define HZ_KEY_PERIOD          ::MyHazel::Key::Period        /* . */
#define HZ_KEY_SLASH           ::MyHazel::Key::Slash         /* / */
#define HZ_KEY_0               ::MyHazel::Key::D0
#define HZ_KEY_1               ::MyHazel::Key::D1
#define HZ_KEY_2               ::MyHazel::Key::D2
#define HZ_KEY_3               ::MyHazel::Key::D3
#define HZ_KEY_4               ::MyHazel::Key::D4
#define HZ_KEY_5               ::MyHazel::Key::D5
#define HZ_KEY_6               ::MyHazel::Key::D6
#define HZ_KEY_7               ::MyHazel::Key::D7
#define HZ_KEY_8               ::MyHazel::Key::D8
#define HZ_KEY_9               ::MyHazel::Key::D9
#define HZ_KEY_SEMICOLON       ::MyHazel::Key::Semicolon     /* ; */
#define HZ_KEY_EQUAL           ::MyHazel::Key::Equal         /* = */
#define HZ_KEY_A               ::MyHazel::Key::A
#define HZ_KEY_B               ::MyHazel::Key::B
#define HZ_KEY_C               ::MyHazel::Key::C
#define HZ_KEY_D               ::MyHazel::Key::D
#define HZ_KEY_E               ::MyHazel::Key::E
#define HZ_KEY_F               ::MyHazel::Key::F
#define HZ_KEY_G               ::MyHazel::Key::G
#define HZ_KEY_H               ::MyHazel::Key::H
#define HZ_KEY_I               ::MyHazel::Key::I
#define HZ_KEY_J               ::MyHazel::Key::J
#define HZ_KEY_K               ::MyHazel::Key::K
#define HZ_KEY_L               ::MyHazel::Key::L
#define HZ_KEY_M               ::MyHazel::Key::M
#define HZ_KEY_N               ::MyHazel::Key::N
#define HZ_KEY_O               ::MyHazel::Key::O
#define HZ_KEY_P               ::MyHazel::Key::P
#define HZ_KEY_Q               ::MyHazel::Key::Q
#define HZ_KEY_R               ::MyHazel::Key::R
#define HZ_KEY_S               ::MyHazel::Key::S
#define HZ_KEY_T               ::MyHazel::Key::T
#define HZ_KEY_U               ::MyHazel::Key::U
#define HZ_KEY_V               ::MyHazel::Key::V
#define HZ_KEY_W               ::MyHazel::Key::W
#define HZ_KEY_X               ::MyHazel::Key::X
#define HZ_KEY_Y               ::MyHazel::Key::Y
#define HZ_KEY_Z               ::MyHazel::Key::Z
#define HZ_KEY_LEFT_BRACKET    ::MyHazel::Key::LeftBracket   /* [ */
#define HZ_KEY_BACKSLASH       ::MyHazel::Key::Backslash     /* \ */
#define HZ_KEY_RIGHT_BRACKET   ::MyHazel::Key::RightBracket  /* ] */
#define HZ_KEY_GRAVE_ACCENT    ::MyHazel::Key::GraveAccent   /* ` */
#define HZ_KEY_WORLD_1         ::MyHazel::Key::World1        /* non-US #1 */
#define HZ_KEY_WORLD_2         ::MyHazel::Key::World2        /* non-US #2 */


#define HZ_KEY_ESCAPE          ::MyHazel::Key::Escape
#define HZ_KEY_ENTER           ::MyHazel::Key::Enter
#define HZ_KEY_TAB             ::MyHazel::Key::Tab
#define HZ_KEY_BACKSPACE       ::MyHazel::Key::Backspace
#define HZ_KEY_INSERT          ::MyHazel::Key::Insert
#define HZ_KEY_DELETE          ::MyHazel::Key::Delete
#define HZ_KEY_RIGHT           ::MyHazel::Key::Right
#define HZ_KEY_LEFT            ::MyHazel::Key::Left
#define HZ_KEY_DOWN            ::MyHazel::Key::Down
#define HZ_KEY_UP              ::MyHazel::Key::Up
#define HZ_KEY_PAGE_UP         ::MyHazel::Key::PageUp
#define HZ_KEY_PAGE_DOWN       ::MyHazel::Key::PageDown
#define HZ_KEY_HOME            ::MyHazel::Key::Home
#define HZ_KEY_END             ::MyHazel::Key::End
#define HZ_KEY_CAPS_LOCK       ::MyHazel::Key::CapsLock
#define HZ_KEY_SCROLL_LOCK     ::MyHazel::Key::ScrollLock
#define HZ_KEY_NUM_LOCK        ::MyHazel::Key::NumLock
#define HZ_KEY_PRINT_SCREEN    ::MyHazel::Key::PrintScreen
#define HZ_KEY_PAUSE           ::MyHazel::Key::Pause
#define HZ_KEY_F1              ::MyHazel::Key::F1
#define HZ_KEY_F2              ::MyHazel::Key::F2
#define HZ_KEY_F3              ::MyHazel::Key::F3
#define HZ_KEY_F4              ::MyHazel::Key::F4
#define HZ_KEY_F5              ::MyHazel::Key::F5
#define HZ_KEY_F6              ::MyHazel::Key::F6
#define HZ_KEY_F7              ::MyHazel::Key::F7
#define HZ_KEY_F8              ::MyHazel::Key::F8
#define HZ_KEY_F9              ::MyHazel::Key::F9
#define HZ_KEY_F10             ::MyHazel::Key::F10
#define HZ_KEY_F11             ::MyHazel::Key::F11
#define HZ_KEY_F12             ::MyHazel::Key::F12
#define HZ_KEY_F13             ::MyHazel::Key::F13
#define HZ_KEY_F14             ::MyHazel::Key::F14
#define HZ_KEY_F15             ::MyHazel::Key::F15
#define HZ_KEY_F16             ::MyHazel::Key::F16
#define HZ_KEY_F17             ::MyHazel::Key::F17
#define HZ_KEY_F18             ::MyHazel::Key::F18
#define HZ_KEY_F19             ::MyHazel::Key::F19
#define HZ_KEY_F20             ::MyHazel::Key::F20
#define HZ_KEY_F21             ::MyHazel::Key::F21
#define HZ_KEY_F22             ::MyHazel::Key::F22
#define HZ_KEY_F23             ::MyHazel::Key::F23
#define HZ_KEY_F24             ::MyHazel::Key::F24
#define HZ_KEY_F25             ::MyHazel::Key::F25

/* Keypad */
#define HZ_KEY_KP_0            ::MyHazel::Key::KP0
#define HZ_KEY_KP_1            ::MyHazel::Key::KP1
#define HZ_KEY_KP_2            ::MyHazel::Key::KP2
#define HZ_KEY_KP_3            ::MyHazel::Key::KP3
#define HZ_KEY_KP_4            ::MyHazel::Key::KP4
#define HZ_KEY_KP_5            ::MyHazel::Key::KP5
#define HZ_KEY_KP_6            ::MyHazel::Key::KP6
#define HZ_KEY_KP_7            ::MyHazel::Key::KP7
#define HZ_KEY_KP_8            ::MyHazel::Key::KP8
#define HZ_KEY_KP_9            ::MyHazel::Key::KP9
#define HZ_KEY_KP_DECIMAL      ::MyHazel::Key::KPDecimal
#define HZ_KEY_KP_DIVIDE       ::MyHazel::Key::KPDivide
#define HZ_KEY_KP_MULTIPLY     ::MyHazel::Key::KPMultiply
#define HZ_KEY_KP_SUBTRACT     ::MyHazel::Key::KPSubtract
#define HZ_KEY_KP_ADD          ::MyHazel::Key::KPAdd
#define HZ_KEY_KP_ENTER        ::MyHazel::Key::KPEnter
#define HZ_KEY_KP_EQUAL        ::MyHazel::Key::KPEqual

#define HZ_KEY_LEFT_SHIFT      ::MyHazel::Key::LeftShift
#define HZ_KEY_LEFT_CONTROL    ::MyHazel::Key::LeftControl
#define HZ_KEY_LEFT_ALT        ::MyHazel::Key::LeftAlt
#define HZ_KEY_LEFT_SUPER      ::MyHazel::Key::LeftSuper
#define HZ_KEY_RIGHT_SHIFT     ::MyHazel::Key::RightShift
#define HZ_KEY_RIGHT_CONTROL   ::MyHazel::Key::RightControl
#define HZ_KEY_RIGHT_ALT       ::MyHazel::Key::RightAlt
#define HZ_KEY_RIGHT_SUPER     ::MyHazel::Key::RightSuper
#define HZ_KEY_MENU            ::MyHazel::Key::Menu