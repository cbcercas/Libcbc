cmake_minimum_required(VERSION 3.7)
project(liblogger)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES
        srcs/logger/logger.c
        srcs/logger/logger_log.c
        srcs/logger/logger_log_dbg.c
        srcs/logger/logger_utils.c)

include_directories(includes ../Libft_corrige/includes)
add_library(liblogger ${SOURCE_FILES})