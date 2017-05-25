cmake_minimum_required(VERSION 3.0)
project(libcbc)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")

# libft
set(SOURCE_FILES
        libft_cbc/srcs/array/array.c
        libft_cbc/srcs/array/array_copy.c
        libft_cbc/srcs/array/array_destroy.c
        libft_cbc/srcs/array/array_growth.c
        libft_cbc/srcs/array/array_insert.c
        libft_cbc/srcs/array/array_pushpop.c
        libft_cbc/srcs/array/array_remove.c
        libft_cbc/srcs/array/array_setget.c
        libft_cbc/srcs/array/array_shrink.c
        libft_cbc/srcs/array/array_swap.c
        libft_cbc/srcs/stack/stack.c
        libft_cbc/srcs/stack/stack_2.c
        libft_cbc/srcs/core/ft_atoi.c
        libft_cbc/srcs/core/ft_bzero.c
        libft_cbc/srcs/core/ft_countchiffres.c
        libft_cbc/srcs/core/ft_ctostr.c
        libft_cbc/srcs/core/ft_freetab.c
        libft_cbc/srcs/core/ft_imtoa.c
        libft_cbc/srcs/core/ft_isalnum.c
        libft_cbc/srcs/core/ft_isalpha.c
        libft_cbc/srcs/core/ft_isascii.c
        libft_cbc/srcs/core/ft_isdigit.c
        libft_cbc/srcs/core/ft_isprint.c
        libft_cbc/srcs/core/ft_iswhitespace.c
        libft_cbc/srcs/core/ft_itoa.c
        libft_cbc/srcs/core/ft_lstadd.c
        libft_cbc/srcs/core/ft_lstdel.c
        libft_cbc/srcs/core/ft_lstdelone.c
        libft_cbc/srcs/core/ft_lstiter.c
        libft_cbc/srcs/core/ft_lstmap.c
        libft_cbc/srcs/core/ft_lstnew.c
        libft_cbc/srcs/core/ft_lstpush.c
        libft_cbc/srcs/core/ft_memalloc.c
        libft_cbc/srcs/core/ft_memccpy.c
        libft_cbc/srcs/core/ft_memchr.c
        libft_cbc/srcs/core/ft_memcmp.c
        libft_cbc/srcs/core/ft_memcpy.c
        libft_cbc/srcs/core/ft_memdel.c
        libft_cbc/srcs/core/ft_memmove.c
        libft_cbc/srcs/core/ft_memset.c
        libft_cbc/srcs/core/ft_nbword.c
        libft_cbc/srcs/core/ft_putchar.c
        libft_cbc/srcs/core/ft_putchar_fd.c
        libft_cbc/srcs/core/ft_putendl.c
        libft_cbc/srcs/core/ft_putendl_fd.c
        libft_cbc/srcs/core/ft_putnbr.c
        libft_cbc/srcs/core/ft_putnbr_fd.c
        libft_cbc/srcs/core/ft_putnstr.c
        libft_cbc/srcs/core/ft_putstr.c
        libft_cbc/srcs/core/ft_putstr_fd.c
        libft_cbc/srcs/core/ft_putwchar.c
        libft_cbc/srcs/core/ft_putwstr.c
        libft_cbc/srcs/core/ft_strcat.c
        libft_cbc/srcs/core/ft_strchr.c
        libft_cbc/srcs/core/ft_strclean.c
        libft_cbc/srcs/core/ft_strclr.c
        libft_cbc/srcs/core/ft_strcmp.c
        libft_cbc/srcs/core/ft_strcpy.c
        libft_cbc/srcs/core/ft_strdel.c
        libft_cbc/srcs/core/ft_strdup.c
        libft_cbc/srcs/core/ft_strequ.c
        libft_cbc/srcs/core/ft_striter.c
        libft_cbc/srcs/core/ft_striteri.c
        libft_cbc/srcs/core/ft_strjoin.c
        libft_cbc/srcs/core/ft_strjoincl.c
        libft_cbc/srcs/core/ft_strlcat.c
        libft_cbc/srcs/core/ft_strlen.c
        libft_cbc/srcs/core/ft_strmap.c
        libft_cbc/srcs/core/ft_strmapi.c
        libft_cbc/srcs/core/ft_strncat.c
        libft_cbc/srcs/core/ft_strncmp.c
        libft_cbc/srcs/core/ft_strncpy.c
        libft_cbc/srcs/core/ft_strnew.c
        libft_cbc/srcs/core/ft_strnstr.c
        libft_cbc/srcs/core/ft_strrchr.c
        libft_cbc/srcs/core/ft_strrev.c
        libft_cbc/srcs/core/ft_strnequ.c
        libft_cbc/srcs/core/ft_strsplit.c
        libft_cbc/srcs/core/ft_strstr.c
        libft_cbc/srcs/core/ft_strsub.c
        libft_cbc/srcs/core/ft_strtabdup.c
        libft_cbc/srcs/core/ft_strtrim.c
        libft_cbc/srcs/core/ft_tablen.c
        libft_cbc/srcs/core/ft_tolower.c
        libft_cbc/srcs/core/ft_toupper.c
        libft_cbc/srcs/core/ft_uitobase.c
        libft_cbc/srcs/core/ft_uitohex.c
        libft_cbc/srcs/core/ft_uitooctal.c
        libft_cbc/srcs/core/ft_wcslen.c
        libft_cbc/srcs/core/ft_wctostr.c
        libft_cbc/srcs/core/ft_wordlen.c
        libft_cbc/srcs/core/ft_wstostr.c
        libft_cbc/srcs/gnl/get_next_line.c
        libft_cbc/srcs/string/string.c
        libft_cbc/srcs/string/string_clean.c
        libft_cbc/srcs/string/string_clone.c
        libft_cbc/srcs/string/string_dup.c
        libft_cbc/srcs/string/string_growth.c
        libft_cbc/srcs/string/string_insert.c
        libft_cbc/srcs/string/string_join.c
        libft_cbc/srcs/string/string_remove.c
        libft_cbc/srcs/string/string_replace.c
        libft_cbc/srcs/string/string_shrink.c
        libft_cbc/srcs/unistd/ft_getopt.c

        # printf
        libftprintfcbc/srcs/ft_printf/ft_parse_args.c
        libftprintfcbc/srcs/ft_printf/ft_parse_args2.c
        libftprintfcbc/srcs/ft_printf/ft_printf.c
        libftprintfcbc/srcs/ft_printf/ft_printf_2.c
        libftprintfcbc/srcs/ft_printf/printer_c.c
        libftprintfcbc/srcs/ft_printf/printer_d.c
        libftprintfcbc/srcs/ft_printf/printer_def.c
        libftprintfcbc/srcs/ft_printf/printer_o.c
        libftprintfcbc/srcs/ft_printf/printer_p.c
        libftprintfcbc/srcs/ft_printf/printer_per.c
        libftprintfcbc/srcs/ft_printf/printer_s.c
        libftprintfcbc/srcs/ft_printf/printer_u.c
        libftprintfcbc/srcs/ft_printf/printer_x.c
        libftprintfcbc/srcs/ft_printf/utils.c

        # logger
        lib_logger_cbc/srcs/logger/logger.c
        lib_logger_cbc/srcs/logger/logger_log.c
        lib_logger_cbc/srcs/logger/logger_log_dbg.c
        lib_logger_cbc/srcs/logger/logger_utils.c

        # tcaps
        lib_tcaps/srcs/tcaps_arrow.c
        lib_tcaps/srcs/tcaps_backspace.c
        lib_tcaps/srcs/tcaps_ctrl_1.c
        lib_tcaps/srcs/tcaps_ctrl_2.c
        lib_tcaps/srcs/tcaps_tab.c
        lib_tcaps/srcs/tcaps_utils.c
        lib_tcaps/srcs/tcaps_size.c
        lib_tcaps/srcs/tcaps_delete.c
        lib_tcaps/srcs/tcaps_moving.c)


include_directories(libft_cbc/includes libftprintfcbc/includes lib_logger_cbc/includes lib_tcaps/includes)

add_library(cbc ${SOURCE_FILES})
