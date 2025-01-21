cmake_minimum_required(VERSION 3.5)

project(container)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest" 
    "googletest"

)
add_executable(
	container
    src/container.cpp
    src/container.hpp
)

add_executable(
    test_list
    test/test_list.cpp
    src/container.hpp
)

target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    test_list PRIVATE
    gtest gtest_main
)

set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)