cmake_minimum_required(VERSION 3.21)

project(Pacman)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(
	Pacman
	src/main.cpp
)

target_link_libraries(Pacman PRIVATE sfml-graphics)
target_compile_features(Pacman PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Pacman POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Pacman> $<TARGET_FILE_DIR:Pacman> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Pacman)