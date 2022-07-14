#include "canpch.h"

#include "Renderer.h"

#include "Shader.h"
#include "Platform/OpenGl/OpenGLShader.h"

namespace Can
{
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{

		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef< OpenGLShader>(name, vertexSrc, fragmentSrc);
		}
		assert(false);
		return nullptr;
	}
	Ref<Shader> Shader::Create(const std::string& filepath )
	{

		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: assert(false); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef< OpenGLShader>(filepath);
		}
		assert(false);
		return nullptr;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{

		auto& name = shader->GetName();
		Add(name, shader);
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{

		assert(!Exists(name));

		m_Shaders[name] = shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& filepath)
	{

		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}
	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{

		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{

		assert(Exists(name));
		return m_Shaders[name];
	}
	bool ShaderLibrary::Exists(const std::string& name) const
	{

		return m_Shaders.find(name) != m_Shaders.end();
	}
}
