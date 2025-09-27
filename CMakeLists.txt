cmake_minimum_required(VERSION 4.0.3)
project(sqlite-clone VERSION 0.1.0 LANGUAGES CXX)

# C++ standard already set in conan profile, but configure here for redundancy
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# main executable
add_executable(${PROJECT_NAME} src/main.cpp)

# tests, (only if BUILD_TESTING is ON)
include(CTest)

if(BUILD_TESTING)
    # conan dependencies
    find_package(GTest REQUIRED)

    # tests executable
    add_executable(${PROJECT_NAME}-tests tests/test_main.cpp)

    # link against gtest + gtest_main
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE GTest::gtest GTest::gtest_main)

    # enable CTest
    enable_testing()

    # GoogleTest helper for automatic test discovery
    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}-tests)

endif()