#include "canpch.h"
#include "Framebuffer.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLFramebuffer.h"

namespace Can
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: assert(false); return nullptr;
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
		}
		assert(false);
		return nullptr;
	}
}
