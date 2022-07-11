#pragma once
#include "Can.h"

namespace Can
{
	struct ButtonConstructorParameters
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
		v4 BorderColor = v4( 0.0f, 0.0f, 0.0f, 1.0f );
	};
	class Button
	{
	public:
		Button(const ButtonConstructorParameters& parameters);
		~Button();

	public:
		entt::registry& sceneRegistry;
		entt::entity entityID;
	};
}
