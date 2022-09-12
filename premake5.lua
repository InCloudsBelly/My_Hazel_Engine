workspace "My_Hazel_Engine"
    architecture "x86_64"
	startproject "Engine_Editor"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

    flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solition directory)
IncludeDir = {}
IncludeDir["GLFW"] = "My_Hazel_Engine/vendor/GLFW/include"
IncludeDir["GLAD"] = "My_Hazel_Engine/vendor/GLAD/include"
IncludeDir["ImGui"] = "My_Hazel_Engine/vendor/imGui"
IncludeDir["glm"] = "My_Hazel_Engine/vendor/glm"
IncludeDir["stb_image"] = "My_Hazel_Engine/vendor/stb_image"

group "Dependencies"
    include "My_Hazel_Engine/vendor/GLFW"
    include "My_Hazel_Engine/vendor/GLAD"
    include "My_Hazel_Engine/vendor/imGui"

group ""

project "My_Hazel_Engine"
    location "My_Hazel_Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "c++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "My_Hazel_Engine/src/hzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }

        defines
    {
        "_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"--windows平台的配置
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS"
        }
    

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        symbols "on"
     
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "on"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        runtime "Release"
        optimize "on"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }


    includedirs
    {
        "My_Hazel_Engine/vendor/spdlog/include",
        "My_Hazel_Engine/src",
        "My_Hazel_Engine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "My_Hazel_Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
        }
    

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        symbols "On"
     
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        runtime "Release"
        optimize "On"

project "Engine_Editor"
        location "Engine_Editor"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        defines
        {
            "HZ_PLATFORM_WINDOWS"
        }

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "My_Hazel_Engine/vendor/spdlog/include",
            "My_Hazel_Engine/src",
            "My_Hazel_Engine/vendor",
            "%{IncludeDir.glm}"
        }

        links
        {
            "My_Hazel_Engine"
        }

        filter "system:windows"
		systemversion "latest"

	    filter "configurations:Debug"
		    defines "HZ_DEBUG"
		    runtime "Debug"
		    symbols "on"

	    filter "configurations:Release"
		    defines "HZ_RELEASE"
		    runtime "Release"
		    optimize "on"

	    filter "configurations:Dist"
		    defines "HZ_DIST"
		    runtime "Release"
		    optimize "on"