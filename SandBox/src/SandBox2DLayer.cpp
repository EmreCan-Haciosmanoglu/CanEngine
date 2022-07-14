#include "canpch.h"
#include "SandBox2DLayer.h"
#include <glm/gtc/type_ptr.hpp>

namespace Can
{
SandBox2DLayer::SandBox2DLayer()
	:Layer("2DLayer")
{
    init_orthographic_camera_controller(m_CameraController, 16.0f / 9.0f, 10.0f, false);
}

void SandBox2DLayer::OnAttach()
{
	m_Tex = Can::Texture2D::Create("assets/textures/Name.png");
	m_Man = Can::Texture2D::Create("assets/textures/Man.png");
	m_Man2 = Can::Texture2D::Create("assets/textures/Man.png");
}
void SandBox2DLayer::OnDetach()
{
}

bool SandBox2DLayer::OnUpdate(TimeStep ts)
{
	m_CameraController.on_update(ts);
	static float rotation = 0.5f;
	rotation += ts * 0.5f;

	Can::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1.0f });
	Can::RenderCommand::Clear();

	Can::Renderer2D::BeginScene(m_CameraController.m_Camera);

	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { 0.0f, -0.2f, 0.0f }, { 1.0f, 1.0f }, 0.0f, { 0.8f, 0.2f, 0.3f, 1.0f }, nullptr });
	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { -0.5f, 1.5f, 0.0f }, { 1.5f, 0.5f }, 0.0f, { 0.2f, 0.8f, 0.3f, 1.0f }, nullptr });
	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { 2.3f, -1.0f, 0.0f }, { 3.5f, 5.0f }, rotation, { 0.8f, 0.3f, 0.8f, 1.0f }, nullptr });

	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { 3.0f, 0.0f, +0.111f }, { 5.0f, 5.0f }, rotation * 2.0f , { 1.0f, 1.0f, 1.0f, 1.0f }, m_Tex });
	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { 3.0f, -3.0f, +0.11f }, { 5.0f, 5.0f }, rotation * 2.0f , { 1.0f, 1.0f, 1.0f, 1.0f }, m_Man2 });
	Can::Renderer2D::DrawQuad(Can::DrawQuadParameters{ { 3.0f, 3.0f, +0.1f }, { 5.0f, 5.0f }, rotation * 2.0f , { 1.0f, 1.0f, 1.0f, 1.0f }, m_Man });

	Can::Renderer2D::EndScene();
    return false;
}

void SandBox2DLayer::OnEvent(Can::Event::Event& event)
{
	m_CameraController.on_event(event);
}
}
