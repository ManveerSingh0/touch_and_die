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
	GIT_SHALLOW ON
)
FetchContent_MakeAvailable(raylib)

add_library(client
	client/player.c
	client/render.c
	client/input.c	
	client/background.c
)

target_link_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/client)
target_link_libraries(client PUBLIC raylib)

add_executable(touch_and_die client/main.c)

target_link_libraries(touch_and_die PRIVATE client)




find_package(Doxygen OPTIONAL_COMPONENTS dot)   # dot = graphviz, for graphs
if(Doxygen_FOUND)
    # Each DOXYGEN_<TAG> variable becomes a <TAG> line in the generated Doxyfile.
    # PROJECT_NAME, PROJECT_NUMBER and PROJECT_BRIEF are filled from project().
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_EXTRACT_ALL           NO)    # undocumented things -> warnings
    set(DOXYGEN_WARN_IF_UNDOCUMENTED  YES)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${PROJECT_SOURCE_DIR}/README.md)

    doxygen_add_docs(docs
        ${PROJECT_SOURCE_DIR}/README.md
        ${PROJECT_SOURCE_DIR}/client
        COMMENT "Generating API documentation with Doxygen"
    )
endif()