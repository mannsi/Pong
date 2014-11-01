
add_compile_options(-std=c++0x) # Use C++ 11 compiler
cmake_minimum_required(VERSION 2.8.4)
project(Pong)

set(SOURCE_FILES World.cpp Ball.cpp Stick.cpp BoxShape.h Collision.cpp OpenGlUi.cpp Commands.h KeyMappingStruct.h )
add_executable(Pong main.cpp ${SOURCE_FILES})

add_subdirectory(Tests/gtest-1.7.0)
add_subdirectory(Tests)

find_package(OpenGL REQUIRED) # Already present
find_package(GLUT REQUIRED) # Followed http://freeglut.sourceforge.net/docs/install.php. Required sudo apt-get install libxmu-dev
find_package(GLEW REQUIRED) # http://glew.sourceforge.net/ Download and sudo make, sudo make install. After that I had to add /usr/lib64/ to /etc/ld.so.conf and run sudo ldconfig
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(Pong ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})
