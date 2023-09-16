cmake_minimum_required(VERSION 3.26.3)

set(PROJECT_NAME goRequest)
project(${PROJECT_NAME})

# Add the include directory where your header files are located.
include_directories(include)

file(GLOB header_files
        "include/jb_lib/jb_int.hpp"
        "include/jb_lib/jb_array.hpp"
        "include/jb_lib/jb_bool.hpp"
        "include/jb_lib/jb_file.hpp"
        "include/jb_lib/jb_vector.hpp"
        "include/go_request/button.hpp"
        "include/go_request/macros.hpp"
        "include/jb_src.hpp"
)

file(GLOB source_files
        "src/main.cpp"
        "src/elements/Button.cpp"
        "src/elements/Colors.cpp"
)

set(SOURCES ${source_files})
set(HEADERS ${header_files})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(lib/jb)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
## target_compile_options(myjbhelpers PRIVATE -g)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-audio sfml-graphics)
target_link_libraries(${PROJECT_NAME} myjbhelpers)
