#include "hzpch.h"
#include "MyHazel/Renderer/VertexArray.h"
#include "MyHazel/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace MyHazel {
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:  HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported !"); return nullptr; break;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}