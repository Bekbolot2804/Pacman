cmake_minimum_required(VERSION 3.21)
project(PacMan LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/Paint/Sprites.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/Paint/YouLose.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/Paint/YouWin.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(PacMan src/main.cpp "src/Enemy/Enemy.cpp" "src/Enemy/Enemy.h" "src/Player/Player.cpp" "src/Player/Player.h")
target_link_libraries(PacMan PRIVATE sfml-graphics)
target_compile_features(PacMan PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET PacMan POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PacMan> $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS PacMan)