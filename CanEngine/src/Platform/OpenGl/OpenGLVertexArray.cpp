#include "canpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Can
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		CAN_PROFILE_FUNCTION();

		switch (type)
		{
		case ShaderDataType::Float: return GL_FLOAT;
		case ShaderDataType::Float2:return GL_FLOAT;
		case ShaderDataType::Float3:return GL_FLOAT;
		case ShaderDataType::Float4:return GL_FLOAT;
		case ShaderDataType::Mat3:return	GL_FLOAT;
		case ShaderDataType::Mat4:return	GL_FLOAT;
		case ShaderDataType::Int:return	GL_INT;
		case ShaderDataType::Int2:return	GL_INT;
		case ShaderDataType::Int3:return	GL_INT;
		case ShaderDataType::Int4:return	GL_INT;
		case ShaderDataType::Bool:return	GL_BOOL;
		}

		CAN_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		CAN_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		CAN_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		CAN_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}
	void OpenGLVertexArray::Unbind() const
	{
		CAN_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexbuffer)
	{
		CAN_PROFILE_FUNCTION();

		CAN_CORE_ASSERT(vertexbuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout");

		glBindVertexArray(m_RendererID);
		vertexbuffer->Bind();
		const auto& layout = vertexbuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(
				m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset
			);
			m_VertexBufferIndex++;
		}
		m_VertexBuffers.push_back(vertexbuffer);
	}
	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexbuffer)
	{
		CAN_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexbuffer->Bind();

		m_IndexBuffer = indexbuffer;
	}
}