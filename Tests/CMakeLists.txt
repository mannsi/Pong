cmake_minimum_required(VERSION 2.8.4)
project(Pong_Tests)

include_directories("gtest-1.7.0/include")
set(test_sources test_main.cpp Test_Collision.cpp Tests_World.cpp ../Collision.cpp ../World.cpp ../Ball.cpp ../Stick.cpp ../BoxShape.h)
add_executable(Pong_Tests ${test_sources})
target_link_libraries(Pong_Tests gtest_main)


