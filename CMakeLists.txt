cmake_minimum_required(VERSION 3.16)
project(FractalsA_P LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

file(GLOB_RECURSE SRC_CPP "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE SRC_H "${SRC_DIR}/*.h")

add_executable(FractalsApp ${SRC_CPP} ${SRC_H})

target_include_directories(FractalsApp PRIVATE ${SRC_DIR})

target_link_libraries(FractalsApp
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)

add_custom_target(rebuild
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMAND ${CMAKE_COMMAND} .
    COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
