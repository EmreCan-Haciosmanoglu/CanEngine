#include "canpch.h"
#include "Can.h"

#include "Can/EntryPoint.h"

#include "imgui.h"
#include <glm/gtc/type_ptr.hpp>

#include "SandBox2DLayer.h"
#include "SandBox3D.h"

namespace Can
{
class Sandbox : public Can::Application
{
public:
	Sandbox(const WindowProps& props)
    :Application(props)
	{
		PushLayer(new SandBox2DLayer());
		//PushLayer(new SandBox3D());
	}

	~Sandbox()
	{
	}
};

Application* CreateApplication(const WindowProps& props)
{
    return new Sandbox(props);
}
}
