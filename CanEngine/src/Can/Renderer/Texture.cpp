#include "canpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLTexture.h"

namespace Can
{
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(width, height);
		}
		assert(false);
		return nullptr;
	}
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(path);
		}
		assert(false);
		return nullptr;
	}
	Ref<Texture2D> Texture2D::Create(uint32_t id, uint32_t width, uint32_t height, const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(id, width, height, path);
		}
		assert(false);
		return nullptr;
	}
}
