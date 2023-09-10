add_library(myjbhelpers
    "src/bool/charIsNum.cpp"
    "src/file/json_obj.cpp"
    "src/int/getNumber.cpp"
    "src/array/strToArray.cpp"
        src/vector/print_vector.cpp
)


target_include_directories(myjbhelpers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(myjbhelpers PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
