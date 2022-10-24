#pragma once

#ifdef SMITHY_PLATFORM_WINDOWS
extern Smithy::Application* Smithy::CreateApplication();

int main(int argc, char** argv) {
	Smithy::Log::Init();
	SMITHY_CORE_WARN("Initialized core log");
	SMITHY_INFO("Initialized client log");

	auto app = Smithy::CreateApplication();
	app->Run();
	delete app;
}
#endif