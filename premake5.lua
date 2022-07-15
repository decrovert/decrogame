workspace "Decrogame"
    architecture "x86_64"
	
    configurations {
        "Debug",
        "Release"
    }

    project "Decrogame"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
        
        targetdir "%{prj.location}/bin/"
        objdir "%{prj.location}/obj/"
        
        files "src/**.cpp"

        links {
            "sfml-system",
            "sfml-graphics",
            "sfml-window"
        }
