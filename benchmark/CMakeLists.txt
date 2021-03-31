cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION &{CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

find_package(benchmark REQUIRED)

file(GLOB benchmark_source_files
    "*.cpp"
)

add_executable(benchmarks ${benchmark_source_files})

target_link_libraries(benchmarks dlm benchmark::benchmark)
