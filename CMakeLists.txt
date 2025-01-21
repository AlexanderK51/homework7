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
    containers_tests
    test/containers_tests.cpp
    test/list_tests.hpp
    test/seq_tests.hpp
    src/container.hpp
)

target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)