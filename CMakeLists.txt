cmake_minimum_required(VERSION 3.20)
project(VisualFun)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED )
find_package(glm REQUIRED )


find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(VisualFun PUBLIC "-pthread")
endif()


add_executable(VisualFun main.cpp Scene/Mesh.cpp Scene/Mesh.h Base/Face.h Base/Vec3.cpp Base/Vec3.h Base/Ray.cpp Base/Ray.h Base/Face.cpp Scene/Camera.cpp Scene/Camera.h Scene/Scene.cpp Scene/Scene.h Utils/BasicGeometry.cpp Utils/BasicGeometry.h FileLoader/STLLoader.cpp FileLoader/STLLoader.h Base/Matrix.cpp Base/Matrix.h)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(VisualFun ${OpenCV_LIBS}  ${CMAKE_THREAD_LIBS_INIT})