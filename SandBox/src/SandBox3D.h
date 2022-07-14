#pragma once
#include "Can/Core.h"
#include "Can.h"
#include "imgui.h"

namespace Can
{
class SandBox3D : public Can::Layer::Layer
{
public:
	SandBox3D();
	virtual ~SandBox3D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual bool OnUpdate(Can::TimeStep ts) override;
	virtual void OnEvent(Can::Event::Event& event) override;
private:
	int m_Resolution = 4;
    Can::Perspective_Camera_Controller m_CameraController;

	Can::Ref<Can::Shader> m_CubeShader;
	Can::Ref<Can::VertexArray> m_CubeVA;
};
}
