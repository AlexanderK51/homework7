cmake_minimum_required(VERSION 3.5)

project(container)

add_executable(
	container
    container.cpp
    container.hpp
)

add_executable(
    test
    test.cpp
    container.hpp
)