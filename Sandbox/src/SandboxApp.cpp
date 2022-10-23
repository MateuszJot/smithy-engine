#include <Smithy.h>

class Sandbox : public Smithy::Application {
public:
	Sandbox() {
	}

	~Sandbox() {

	}
};

Smithy::Application* Smithy::CreateApplication() {
	return new Sandbox();
}