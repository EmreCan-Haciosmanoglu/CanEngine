#pragma once
#include "Can/Core.h"
#include <entt/entt.hpp>

namespace Can
{
	struct ScrollBarConstructorParameters;
	class ScrollBar;
	struct ScrollViewConstructorParameters
	{
		entt::registry& Registry;
		entt::entity Parent = entt::null;
		v3 Position = v3(0.0f);
		v2 Size = v2(1.0f);
		v4 Color = v4(1.0f);
		
		uint8_t scrollPosition = 0;
		// 0 -> top
		// 1 -> right
		// 2 -> bottom
		// 3 -> left

		std::function<void()> OnClick;
		float borderRadius = 0.0f;
		bool border = false;
		v4 BorderColor = v4(0.0f, 0.0f, 0.0f, 1.0f);
	};

	class ScrollView
	{
	public:
		ScrollView(ScrollViewConstructorParameters& parameters,	ScrollBarConstructorParameters _ScrollBarConstructorParameters);
		~ScrollView();

		void Update();
	public:
		entt::registry& sceneRegistry;
		entt::entity entityID;

		ScrollBar* scrollbar = nullptr;
	};
}
