#pragma once

#include "Core.h"

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
