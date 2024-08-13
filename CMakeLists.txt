cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SnakeGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Snake.cpp
)

# Specify the include directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add executable
add_executable(SnakeGame ${SOURCES})

# Link SFML libraries
target_link_libraries(SnakeGame sfml-graphics sfml-window sfml-system)

