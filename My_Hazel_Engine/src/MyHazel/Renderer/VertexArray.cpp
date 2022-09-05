#include "hzpch.h"
#include "VertexArray.h"
#include "Renderer.h"

#include "MyHazel/Platform/OpenGL/OpenGLVertexArray.h"

namespace MyHazel {
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:  HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported !"); return nullptr; break;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray() ;
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}