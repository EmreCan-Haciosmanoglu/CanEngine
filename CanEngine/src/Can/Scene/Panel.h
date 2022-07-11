#pragma once
#include "Can.h"
#include <entt/entt.hpp>

namespace Can
{
	struct PanelConstructorParameters
	{
		entt::registry& Registry;
		entt::entity Parent = entt::null;
        v3 Position = v3(0.0f);
		v2 Size = v2(1.0f);
		v4 Color = v4(1.0f);
		Ref<Texture2D> Texture = nullptr;
		std::function<void()> OnClick;
		float borderRadius = 0.0f;
		bool border = false;
		const v4 BorderColor{ 0.0f, 0.0f, 0.0f, 1.0f };
	};

	class Panel
	{
	public:
		Panel(const PanelConstructorParameters& parameters);
		~Panel();

	public:
		entt::registry& sceneRegistry;
		entt::entity entityID;
	};
}
