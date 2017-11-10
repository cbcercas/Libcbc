cmake_minimum_required(VERSION 3.6)
project(tcaps)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        includes/libtcaps.h
        srcs/tcaps_arrow.c
        srcs/tcaps_backspace.c
        srcs/tcaps_ctrl_1.c
        srcs/tcaps_ctrl_2.c
        srcs/tcaps_tab.c
        srcs/tcaps_utils.c
        srcs/tcaps_size.c
        srcs/tcaps_delete.c
        srcs/tcaps_moving.c
        srcs/tcaps_home_end.c
        srcs/tcaps_escape.c
        srcs/tcaps_video.c
        )

include_directories(includes)
include_directories(../libft/includes)

add_library(tcaps ${SOURCE_FILES})
