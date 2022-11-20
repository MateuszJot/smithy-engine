#include "Application.h"

#include "Smithy/Events/ApplicationEvent.h"
#include "Smithy/Log.h"

namespace Smithy {
	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() 
	{
		//event test
		WindowResizeEvent e(1280, 720);
		SMITHY_TRACE(e);

		while(true);
	}
}