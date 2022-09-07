#include "hzpch.h"

#include "MyHazel/Renderer/RenderCommand.h"

namespace MyHazel {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

} 