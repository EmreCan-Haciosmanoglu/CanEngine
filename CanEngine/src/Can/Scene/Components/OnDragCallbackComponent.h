#pragma once
#include "Can.h"

namespace Can
{
	struct OnDragCallbackComponent
	{
		OnDragCallbackComponent(const OnDragCallbackComponent&) = default;
		OnDragCallbackComponent(const std::function<void()>& callback);

		operator std::function<void()>& () { return Callback; }
		operator const std::function<void()>& () const { return Callback; }

		void operator()() { Callback(); }
		void operator()() const { Callback(); }

		std::function<void()> Callback;
	};
}