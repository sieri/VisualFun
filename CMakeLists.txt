cmake_minimum_required(VERSION 3.20)
project(VisualFun)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED )

add_executable(VisualFun main.cpp Base/Mesh.cpp Base/Mesh.h Base/Structures.h Base/Structures.cpp Base/Camera.cpp Base/Camera.h Base/Scene.cpp Base/Scene.h)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(VisualFun ${OpenCV_LIBS} )