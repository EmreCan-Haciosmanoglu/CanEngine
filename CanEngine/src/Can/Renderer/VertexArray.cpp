#include "canpch.h"
#include "VertexArray.h"
#include "Platform/OpenGl/OpenGLVertexArray.h"

#include "Renderer.h"
namespace Can
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}
		CAN_CORE_ASSERT(false, "Unknown RendererAPI!!!");
		return nullptr;
	}
}
