#pragma once

#ifdef SMITHY_PLATFORM_WINDOWS
extern Smithy::Application* Smithy::CreateApplication();

int main(int argc, char** argv) {
	printf("Smithy Engine");
	auto app = Smithy::CreateApplication();
	app->Run();
	delete app;
}
#endif