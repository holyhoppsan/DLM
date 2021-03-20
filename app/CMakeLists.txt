cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION &{CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# setup imgui
add_library(imgui
    ../imgui/imconfig.h
    ../imgui/imgui.cpp
    ../imgui/imgui.h
    ../imgui/imgui_demo.cpp
    ../imgui/imgui_draw.cpp
    ../imgui/imgui_internal.h
    ../imgui/imgui_widgets.cpp
    ../imgui/imgui_tables.cpp
    ../imgui/imstb_rectpack.h
    ../imgui/imstb_textedit.h
    ../imgui/imstb_truetype.h
    ../imgui/imgui_impl_opengl3.cpp
    ../imgui/imgui_impl_opengl3.h
    ../imgui/imgui_impl_sdl.cpp
    ../imgui/imgui_impl_sdl.h
)

target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(imgui PUBLIC "../imgui/")
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_CUSTOM=<SDL_opengl.h>  GL_GLEXT_PROTOTYPES=1)

# setup dlm app
file(GLOB dlm_app_source_files
    "*.cpp"
)

add_executable(dlm_app ${dlm_app_source_files})

target_include_directories(dlm_app PUBLIC "../imgui/")
target_include_directories(dlm_app PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(dlm_app PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(dlm_app PUBLIC ${GLEW_INCLUDE_DIRS})

message(STATUS "SDL PATH: <<${SDL2_INCLUDE_DIRS}>>")
message(STATUS "OPENGL PATH: <<${OPENGL_INCLUDE_DIR}>>")
message(STATUS "GLEW PATH: <<${OPENGL_INCLUDE_DIR}>>")

target_link_libraries(dlm_app dlm)
target_link_libraries(dlm_app ${SDL2_LIBRARIES})
target_link_libraries(dlm_app ${OPENGL_LIBRARIES})
target_link_libraries(dlm_app ${GLEW_LIBRARIES})
target_link_libraries(dlm_app imgui)

target_compile_features(dlm_app PUBLIC cxx_std_17)
