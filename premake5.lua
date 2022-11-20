workspace "smithy"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Smithy"
	location "Smithy"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sypch.h"
	pchsource "Smithy/src/sypch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SMITHY_PLATFORM_WINDOWS",
			"SMITHY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SMITHY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SMITHY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SMITHY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Smithy/vendor/spdlog/include",
		"Smithy/src"
	}

	links 
	{
		"Smithy"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SMITHY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SMITHY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SMITHY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SMITHY_DIST"
		optimize "On"