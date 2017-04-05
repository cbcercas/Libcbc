cmake_minimum_required(VERSION 3.6)
project(libtcaps)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        includes/libtcaps.h
        srcs/tcaps_arrow.c
        srcs/tcaps_backspace.c
        srcs/tcaps_ctrl_1.c
        srcs/tcaps_ctrl_2.c
        srcs/tcaps_tab.c
        srcs/tcaps_utils.c)

include_directories(includes)
add_library(libtcaps ${SOURCE_FILES})
