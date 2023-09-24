add_library(myjbhelpers
    "src/bool/char_is_num.cpp"
    "src/bool/check_str_last_index.cpp"
    "src/file/json_obj.cpp"
    "src/int/get_number.cpp"
    "src/int/str_len.cpp"
        "src/vector/str_to_vector.cpp"
)


target_include_directories(myjbhelpers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(myjbhelpers PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
## target_compile_options(myjbhelpers PRIVATE -g)