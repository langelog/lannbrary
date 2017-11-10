cmake_minimum_required (VERSION 2.8.11)

project (Lannbrary)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# bring the headers
include_directories(include)

# wildcast addition of sources:
file(GLOB SOURCES "src/*.cpp")

add_executable(lannbrary ${SOURCES})


