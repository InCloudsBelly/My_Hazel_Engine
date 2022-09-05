#include "hzpch.h"
#include "RenderCommand.h"
#include "MyHazel/Platform/OpenGL/OpenGLRendererAPI.h"

namespace MyHazel {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;


} 