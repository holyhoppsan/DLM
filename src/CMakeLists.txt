cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION &{CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# file(GLOB dlm_source_files
#     "*.cpp"
# )

add_library(dlm INTERFACE)
                       
target_compile_features(dlm INTERFACE cxx_std_17)

target_include_directories(dlm INTERFACE ${CMAKE_SOURCE_DIR}/include)
