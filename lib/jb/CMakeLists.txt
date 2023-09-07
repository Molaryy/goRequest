# Create a library from the source files in the "src" directory
add_library(myjbhelpers
    "src/bool/charIsNum.cpp"
    "src/file/get-json.cpp"
    "src/int/getNumber.cpp"
)

# Add include directories so that the header files can be included
target_include_directories(myjbhelpers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Optionally, set C++ standard for the library
set_target_properties(myjbhelpers PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
