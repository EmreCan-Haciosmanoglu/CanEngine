#pragma once
#include "Can.h"
#include "Can/Renderer/Renderer2D.h"
#include "imgui.h"

namespace Can
{
class SandBox2DLayer : public Can::Layer::Layer
{
public:
	SandBox2DLayer();
	virtual ~SandBox2DLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual bool OnUpdate(Can::TimeStep ts) override;
	virtual void OnEvent(Can::Event::Event& event) override;
private:
    Orthographic_Camera_Controller m_CameraController;

	Ref<Can::Shader> m_SquareShader;
	Ref<Can::VertexArray> m_SquareVA;

	Ref<Can::Texture2D> m_Tex;
	Ref<Can::Texture2D> m_Man;
	Ref<Can::Texture2D> m_Man2;

	glm::vec4 m_SquareColor = { 0.0f, 1.0f, 0.0f, 1.0f };

};
}
