cmake_minimum_required(VERSION 3.26.1)

project(Leetcode_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

option(BUILD_TEST "Build test expecutable" ON)

if(BUILD_TEST) 
  add_subdirectory(test)
endif()
