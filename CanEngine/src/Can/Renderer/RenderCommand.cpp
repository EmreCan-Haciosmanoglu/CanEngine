#include "canpch.h"
#include "RenderCommand.h"

#ifdef CAN_PLATFORM_OPENGL
#include "Platform/OpenGl/OpenGLRendererAPI.h"
#else
#include "Platform/Metal/MetalRendererAPI.h"
#endif

namespace Can
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
