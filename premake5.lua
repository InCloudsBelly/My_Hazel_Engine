workspace "My_Hazel_Engine"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solition directory)
IncludeDir = {}
IncludeDir["GLFW"] = "My_Hazel_Engine/vendor/GLFW/include"
IncludeDir["GLAD"] = "My_Hazel_Engine/vendor/GLAD/include"
IncludeDir["imGui"] = "My_Hazel_Engine/vendor/imGui/include"

include "My_Hazel_Engine/vendor/GLFW"
include "My_Hazel_Engine/vendor/GLAD"
include "My_Hazel_Engine/vendor/imGui"

project "My_Hazel_Engine"
    location "My_Hazel_Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "My_Hazel_Engine/src/hzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.imGui}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "imGui",
        "opengl32.lib"
    }

    filter "system:windows"--windows平台的配置
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands -- build后的自定义命令
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") --拷贝引擎dll库到sanbox.exe的同一目录下去
        }
    

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        buildoptions "/MDd"
        symbols "On"
     
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        buildoptions "MD"
        optimize "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "c++"

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
        "My_Hazel_Engine/src"
    }

    links
    {
        "My_Hazel_Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
        }
    

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        buildoptions "/MDd"
        symbols "On"
     
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        buildoptions "MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        buildoptions "MD"
        optimize "On"