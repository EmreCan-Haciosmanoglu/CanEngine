#include "canpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGl/OpenGLRendererAPI.h"

namespace Can
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    assert(false); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		assert(false);
		return nullptr;
	}

}
