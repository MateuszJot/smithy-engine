#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Smithy {
	class SMITHY_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define SMITHY_CORE_TRACE(...) ::Smithy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SMITHY_CORE_INFO(...)  ::Smithy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SMITHY_CORE_WARN(...)  ::Smithy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SMITHY_CORE_ERROR(...) ::Smithy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SMITHY_CORE_FATAL(...) ::Smithy::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SMITHY_TRACE(...) ::Smithy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SMITHY_INFO(...)  ::Smithy::Log::GetClientLogger()->info(__VA_ARGS__)
#define SMITHY_WARN(...)  ::Smithy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SMITHY_ERROR(...) ::Smithy::Log::GetClientLogger()->error(__VA_ARGS__)
#define SMITHY_FATAL(...) ::Smithy::Log::GetClientLogger()->fatal(__VA_ARGS__)