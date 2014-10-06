# TODO How can I not include a list of all my source files in Tests/CMakeLists.txt ? I don't think they should be listed at all there.
# TODO How can I have the Pong project run all the tests every time it runs/builds ?
# TODO Would be nice to get rid of boost dependency

cmake_minimum_required(VERSION 2.8.4)
project(Pong)

set(SOURCE_FILES World.cpp Ball.cpp Stick.cpp KeyboardInput.cpp BoxShape.h Collision.cpp DrawingStuff.h)
add_executable(Pong main.cpp ${SOURCE_FILES})

add_subdirectory(Tests/gtest-1.7.0)
add_subdirectory(Tests)

#Boost
set(Boost_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../boostInstall/include)
find_package(Boost 1.56.0 REQUIRED COMPONENTS system date_time thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(Pong ${Boost_LIBRARIES})
endif()

