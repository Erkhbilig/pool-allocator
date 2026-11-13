cmake_minimum_required(VERSION 3.23)
project(pool-allocator) # When called, it ensures that CMake will adopt the behavior of the listed version

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

set(CMAKE_CXX_STANDARD 20) # Setting the C++ standard to C++20 and requiring it
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OFF CACHE BOOL (Comes before the fetch, as the library reads them while they are being added
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    Google_Benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.10.0
)
FetchContent_MakeAvailable(Google_Benchmark)

add_executable(pool_bench bench/bench_main.cpp)
target_include_directories(pool_bench PRIVATE include/)
target_link_libraries(pool_bench PRIVATE benchmark::benchmark_main)
