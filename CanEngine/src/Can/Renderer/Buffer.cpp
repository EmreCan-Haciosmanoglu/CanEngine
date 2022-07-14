#include "canpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLBuffer.h"
namespace Can
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size, bool isDynamic)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef< OpenGLVertexBuffer>(vertices, size, isDynamic);
		}
        assert(false);
		return nullptr;
	}
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(size);
		}
        assert(false);
		return nullptr;
	}
	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, count);
		}
        assert(false);
		return nullptr;
	}
}
