cmake_minimum_required(VERSION 3.7)
project(libftprintf)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES
        srcs/ft_printf/ft_parse_args.c
        srcs/ft_printf/ft_parse_args2.c
        srcs/ft_printf/ft_printf.c
        srcs/ft_printf/ft_printf_2.c
        srcs/ft_printf/printer_c.c
        srcs/ft_printf/printer_d.c
        srcs/ft_printf/printer_def.c
        srcs/ft_printf/printer_o.c
        srcs/ft_printf/printer_p.c
        srcs/ft_printf/printer_per.c
        srcs/ft_printf/printer_s.c
        srcs/ft_printf/printer_u.c
        srcs/ft_printf/printer_x.c
        srcs/ft_printf/utils.c)

include_directories(includes ../Libft_corrige/includes)
add_library(ftprintf ${SOURCE_FILES})