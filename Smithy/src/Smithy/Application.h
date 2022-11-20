#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Smithy {
	class SMITHY_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in a client
	Application* CreateApplication();
}
