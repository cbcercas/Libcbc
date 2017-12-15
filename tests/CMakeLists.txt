
set(SOURCE_FILES_TESTS
        srcs/array/test_array_simple_usage.c
        srcs/array/test_array_create.c
        srcs/stack/test_stack.c
        srcs/string/test_string_clone.c
        srcs/string/test_string_create.c
        srcs/string/test_string_dup.c
        srcs/string/test_string_insert.c
        srcs/string/test_string_join.c
        srcs/string/test_string_remove.c
        srcs/string/test_string_replace.c
        srcs/string/test_string_shrink.c
        )

include_directories(includes ../../Criterion/include)

add_executable(test_cbc ${SOURCE_FILES_TESTS})

LINK_DIRECTORIES(../../Criterion/build)

target_link_libraries(test_cbc cbc criterion)