#include "canpch.h"
#include "SandBox3D.h"
#include "Can/Core.h"

namespace Can
{
SandBox3D::SandBox3D()
: Layer("3D Layer")
, m_CameraController(
    45.0f,
    16.0f / 9.0f,
    0.1f,
    1000.0f,
    v3{ 2.0f, -3.0f, 5.0f },
    v3{ 0.0f, -45.0f, 90.0f }
)
{
}

void SandBox3D::OnAttach()
{
}
void SandBox3D::OnDetach()
{
}

bool SandBox3D::OnUpdate(Can::TimeStep ts)
{
    m_CameraController.on_update(ts);
    
    Can::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1.0f });
    Can::RenderCommand::Clear();
    
    Can::Renderer3D::BeginScene(m_CameraController.camera);
    
    //Can::Renderer3D::DrawCube({ 0.0f, 0.0f, -4.0f }, { 0.5f, 0.5f, 0.5f });
    
    Can::Renderer2D::EndScene();
    return false;
}

void SandBox3D::OnEvent(Can::Event::Event & event)
{
    m_CameraController.on_event(event);
}

}
