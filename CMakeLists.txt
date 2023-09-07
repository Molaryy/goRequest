cmake_minimum_required(VERSION 3.26.3)

set(PROJECT_NAME goRequest)
project(${PROJECT_NAME})

# Add the include directory where your header files are located.
include_directories(include)

file(GLOB header_files
        "include/jb_array.hpp"
        "include/jb_bool.hpp"
        "include/jb_file.hpp"
        "include/jb_int.hpp"
        "include/jb_src.hpp"
)

file(GLOB source_files
        "src/main.cpp"
)

set(SOURCES ${source_files})
set(HEADERS ${header_files})
set(CMAKE_CXX_STANDARD 11)

# Include the "lib/jb" directory as a subdirectory
add_subdirectory(lib/jb)

# Set the output directory for the executable to the source root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link the required SFML libraries.
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-audio sfml-graphics)

# Link your "myjbhelpers" library to the main executable
target_link_libraries(${PROJECT_NAME} myjbhelpers)
