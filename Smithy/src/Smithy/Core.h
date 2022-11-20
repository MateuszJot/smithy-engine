#pragma once

#ifdef SMITHY_PLATFORM_WINDOWS
	#ifdef SMITHY_BUILD_DLL
		#define SMITHY_API __declspec(dllexport)
	#else
		#define SMITHY_API __declspec(dllimport)
	#endif
#else
	#error Smithy only supports Windows!
#endif

#define BIT(x) (1 << x)