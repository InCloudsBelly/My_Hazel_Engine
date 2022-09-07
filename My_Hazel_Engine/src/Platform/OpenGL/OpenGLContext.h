#pragma once

#include "MyHazel/Renderer/GraphicsContext.h"
struct GLFWwindow;

namespace MyHazel {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow * windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;


	private:
		GLFWwindow* m_windowHandle;
	};
}