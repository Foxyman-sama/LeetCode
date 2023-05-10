cmake_minimum_required(VERSION 3.8)
project(LeetCode)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}  
	main.cpp
	leetcode.hpp
)
