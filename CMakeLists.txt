cmake_minimum_required(VERSION 3.5)
project(pacman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

# Google Test
SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)
add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

file(GLOB SOURCE_FILES src/*.cpp src/utils/*.cpp src/headers/*.h src/headers/*.hpp src/*.hpp)


add_executable(runTests ${SOURCE_FILES} tests/tests.cpp)
add_executable(main ${SOURCE_FILES} src/main.cpp)
target_compile_definitions(main PUBLIC MAIN)
target_compile_definitions(runTests PUBLIC TESTS)

target_link_libraries(runTests gtest gtest_main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++fs)
target_link_libraries(main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++fs)

add_test(runTests tests.cpp)

add_custom_target(runValgrind
        valgrind --leak-check=full -v ./runTests 2>&1
        DEPENDS runTests)
