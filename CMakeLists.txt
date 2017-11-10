cmake_minimum_required(VERSION 3.0)
project(libcbc)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")

# libft
set(SOURCE_FILES
        libft/srcs/array/array.c
        libft/srcs/array/array_copy.c
        libft/srcs/array/array_destroy.c
        libft/srcs/array/array_growth.c
        libft/srcs/array/array_insert.c
        libft/srcs/array/array_pushpop.c
        libft/srcs/array/array_remove.c
        libft/srcs/array/array_setget.c
        libft/srcs/array/array_shrink.c
        libft/srcs/array/array_swap.c
        libft/srcs/stack/stack.c
        libft/srcs/stack/stack_2.c
        libft/srcs/core/ft_atoi.c
        libft/srcs/core/ft_bzero.c
        libft/srcs/core/ft_countchiffres.c
        libft/srcs/core/ft_ctostr.c
        libft/srcs/core/ft_freetab.c
        libft/srcs/core/ft_imtoa.c
        libft/srcs/core/ft_isalnum.c
        libft/srcs/core/ft_isalpha.c
        libft/srcs/core/ft_isascii.c
        libft/srcs/core/ft_isdigit.c
        libft/srcs/core/ft_isprint.c
        libft/srcs/core/ft_iswhitespace.c
        libft/srcs/core/ft_itoa.c
        libft/srcs/core/ft_lstadd.c
        libft/srcs/core/ft_lstdel.c
        libft/srcs/core/ft_lstdelone.c
        libft/srcs/core/ft_lstiter.c
        libft/srcs/core/ft_lstmap.c
        libft/srcs/core/ft_lstnew.c
        libft/srcs/core/ft_lstpush.c
        libft/srcs/core/ft_memalloc.c
        libft/srcs/core/ft_memccpy.c
        libft/srcs/core/ft_memchr.c
        libft/srcs/core/ft_memcmp.c
        libft/srcs/core/ft_memcpy.c
        libft/srcs/core/ft_memdel.c
        libft/srcs/core/ft_memmove.c
        libft/srcs/core/ft_memset.c
        libft/srcs/core/ft_nbword.c
        libft/srcs/core/ft_putchar.c
        libft/srcs/core/ft_putchar_fd.c
        libft/srcs/core/ft_putendl.c
        libft/srcs/core/ft_putendl_fd.c
        libft/srcs/core/ft_putnbr.c
        libft/srcs/core/ft_putnbr_fd.c
        libft/srcs/core/ft_putnstr.c
        libft/srcs/core/ft_putstr.c
        libft/srcs/core/ft_putstr_fd.c
        libft/srcs/core/ft_putwchar.c
        libft/srcs/core/ft_putwstr.c
        libft/srcs/core/ft_strcat.c
        libft/srcs/core/ft_strchr.c
        libft/srcs/core/ft_strclean.c
        libft/srcs/core/ft_strclr.c
        libft/srcs/core/ft_strcmp.c
        libft/srcs/core/ft_strcpy.c
        libft/srcs/core/ft_strdel.c
        libft/srcs/core/ft_strdup.c
        libft/srcs/core/ft_strequ.c
        libft/srcs/core/ft_striter.c
        libft/srcs/core/ft_striteri.c
        libft/srcs/core/ft_strjoin.c
        libft/srcs/core/ft_strjoincl.c
        libft/srcs/core/ft_strlcat.c
        libft/srcs/core/ft_strlen.c
        libft/srcs/core/ft_strmap.c
        libft/srcs/core/ft_strmapi.c
        libft/srcs/core/ft_strncat.c
        libft/srcs/core/ft_strncmp.c
        libft/srcs/core/ft_strncpy.c
        libft/srcs/core/ft_strnew.c
        libft/srcs/core/ft_strnstr.c
        libft/srcs/core/ft_strrchr.c
        libft/srcs/core/ft_strrev.c
        libft/srcs/core/ft_strnequ.c
        libft/srcs/core/ft_strsplit.c
        libft/srcs/core/ft_strstr.c
        libft/srcs/core/ft_strsub.c
        libft/srcs/core/ft_strtabdup.c
        libft/srcs/core/ft_strtrim.c
        libft/srcs/core/ft_tablen.c
        libft/srcs/core/ft_tolower.c
        libft/srcs/core/ft_toupper.c
        libft/srcs/core/ft_uitobase.c
        libft/srcs/core/ft_uitohex.c
        libft/srcs/core/ft_uitooctal.c
        libft/srcs/core/ft_wcslen.c
        libft/srcs/core/ft_wctostr.c
        libft/srcs/core/ft_wordlen.c
        libft/srcs/core/ft_wstostr.c
        libft/srcs/gnl/get_next_line.c
        libft/srcs/string/string.c
        libft/srcs/string/string_clean.c
        libft/srcs/string/string_clone.c
        libft/srcs/string/string_dup.c
        libft/srcs/string/string_growth.c
        libft/srcs/string/string_insert.c
        libft/srcs/string/string_join.c
        libft/srcs/string/string_remove.c
        libft/srcs/string/string_replace.c
        libft/srcs/string/string_shrink.c
        libft/srcs/unistd/ft_getopt.c
        libft/srcs/libgen/ft_basename.c

        # printf
        libftprintf/srcs/ft_printf/ft_parse_args.c
        libftprintf/srcs/ft_printf/ft_parse_args2.c
        libftprintf/srcs/ft_printf/ft_printf.c
        libftprintf/srcs/ft_printf/ft_printf_2.c
        libftprintf/srcs/ft_printf/printer_c.c
        libftprintf/srcs/ft_printf/printer_d.c
        libftprintf/srcs/ft_printf/printer_def.c
        libftprintf/srcs/ft_printf/printer_o.c
        libftprintf/srcs/ft_printf/printer_p.c
        libftprintf/srcs/ft_printf/printer_per.c
        libftprintf/srcs/ft_printf/printer_s.c
        libftprintf/srcs/ft_printf/printer_u.c
        libftprintf/srcs/ft_printf/printer_x.c
        libftprintf/srcs/ft_printf/utils.c

        # logger
        liblogger/srcs/logger/logger.c
        liblogger/srcs/logger/logger_log.c
        liblogger/srcs/logger/logger_log_dbg.c
        liblogger/srcs/logger/logger_utils.c

        # tcaps

        libtcaps/srcs/tcaps_alt.c
        libtcaps/srcs/tcaps_alt_arrow.c
        libtcaps/srcs/tcaps_arrow.c
        libtcaps/srcs/tcaps_backspace.c
        libtcaps/srcs/tcaps_ctrl_1.c
        libtcaps/srcs/tcaps_ctrl_2.c
        libtcaps/srcs/tcaps_ctrl_arrow.c
        libtcaps/srcs/tcaps_delete.c
        libtcaps/srcs/tcaps_home_end.c
        libtcaps/srcs/tcaps_insert.c
        libtcaps/srcs/tcaps_moving.c
        libtcaps/srcs/tcaps_moving_2.c
        libtcaps/srcs/tcaps_size.c
        libtcaps/srcs/tcaps_tab.c
        libtcaps/srcs/tcaps_utils.c
        libtcaps/srcs/tcaps_bell.c
        libtcaps/srcs/tcaps_escape.c
        libtcaps/srcs/tcaps_video.c
        )


include_directories(libft/includes libftprintf/includes liblogger/includes libtcaps/includes)

add_library(cbc ${SOURCE_FILES})
