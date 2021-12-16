cmake_minimum_required(VERSION 3.20)
project(VisualFun)
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_C_FLAGS "-Wall -D_REENTRANT")
set(CMAKE_CXX_FLAGS "-Wall -D_REENTRANT")

if(UNIX)
    set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb3 -Wextra -mtune=native")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb3 -Wextra -mtune=native")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -mtune=generic -flto -ggdb3 -Wextra")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -mtune=generic -flto -ggdb3 -Wextra")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -mtune=generic -flto")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -mtune=generic -flto")
else()
    add_compile_definitions(_USE_MATH_DEFINES)
    set(CMAKE_C_FLAGS_DEBUG "-O2 -mtune=native")
    set(CMAKE_CXX_FLAGS_DEBUG "-O2 -mtune=native")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -mtune=generic -flto")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -mtune=generic -flto")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -mtune=generic -flto")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -mtune=generic -flto")
endif()

find_package(OpenCV REQUIRED )

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(VisualFun PUBLIC "-pthread")
endif()

# move the resources
file(COPY imgs DESTINATION ${CMAKE_BINARY_DIR})

add_executable(VisualFun main.cpp Scene/Mesh.cpp Scene/Mesh.h Base/Face.h Base/Vec3.cpp Base/Vec3.h Base/Ray.cpp Base/Ray.h Base/Face.cpp Scene/Camera.cpp Scene/Camera.h Scene/Scene.cpp Scene/Scene.h Utils/BasicGeometry.cpp Utils/BasicGeometry.h FileLoader/STLLoader.cpp FileLoader/STLLoader.h Base/Matrix.cpp Base/Matrix.h)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(VisualFun ${OpenCV_LIBS}  ${CMAKE_THREAD_LIBS_INIT})
