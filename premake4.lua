solution "bullwhip"
	configurations { "Debug", "Release" }


	project "bullwhip"
		kind "ConsoleApp"
		language "C++"
		files { "**.hpp", "**.cpp" }
		excludes { "editor/**.h", "editor/**.cpp", "entites/**.h", "entites/**.cpp", "libs/**.cpp", "libs/**.h", "Player.cpp", "Player.h" }
		links { "Box2D", "sfml-system", "sfml-window", "sfml-graphics" }
		includedirs { "./" }

		configuration "Debug"
			defines {"DEBUG"}
			flags { "Symbols" }

		configuration "Release"
			defines {"NDEBUG"}
			flags { "Optimize" }


		configuration { "linux", "gmake" }
			buildoptions { "-std=c++0x" }
