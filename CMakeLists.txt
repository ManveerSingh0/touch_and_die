cmake_minimum_required(VERSION 4.4)

project(touch_and_die
	VERSION 0.1.0
	DESCRIPTION "touch and die is a multiplayer game where player dodge each other , last one alive wins"
	LANGUAGES C
)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 6.2
)
FetchContent_MakeAvailable(raylib)

add_executable(touch_and_die client/main.c)

target_link_libraries(touch_and_die PRIVATE raylib)