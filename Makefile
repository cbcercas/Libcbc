# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/17 17:00:14 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libcbc.a

# Libft sources
SRC_SUBDIR		+= libft/srcs/core
SRCS			+= ft_atoi.c ft_bzero.c ft_countchiffres.c ft_ctostr.c \
ft_freetab.c ft_imtoa.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_iswhitespace.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstpush.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_nbword.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnstr.c ft_putstr.c \
ft_putstr_fd.c ft_putwchar.c ft_putwstr.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoincl.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtabdup.c ft_strtrim.c ft_tablen.c \
ft_tolower.c ft_toupper.c ft_uitobase.c ft_uitohex.c ft_uitooctal.c \
ft_wcslen.c ft_wctostr.c ft_wordlen.c ft_wstostr.c ft_strclean.c

SRC_SUBDIR		+= libft/srcs/gnl
SRCS			+= get_next_line.c

SRC_SUBDIR		+= libft/srcs/array
SRCS			+= array.c array_copy.c array_growth.c array_shrink.c array_setget.c \
array_pushpop.c array_insert.c array_destroy.c array_swap.c array_remove.c

SRC_SUBDIR		+= libft/srcs/string
SRCS			+= string.c string_growth.c string_dup.c string_clone.c \
string_insert.c string_join.c string_clean.c string_remove.c string_shrink.c \
string_replace.c

SRC_SUBDIR      += libft/srcs/unistd
SRCS            += ft_getopt.c

SRC_SUBDIR      += libft/srcs/stack
SRCS            += stack.c stack_2.c

# Ft printf sources

SRC_SUBDIR		+= libftprintf/srcs/ft_printf
SRCS			+= ft_printf.c ft_printf_2.c ft_parse_args.c ft_parse_args2.c \
					utils.c printer_s.c printer_d.c printer_o.c printer_p.c \
					printer_u.c printer_x.c printer_c.c printer_per.c \
					printer_def.c

# Logger sources
SRC_SUBDIR		+= liblogger/srcs/logger
SRCS			+= logger.c logger_utils.c logger_log.c logger_log_dbg.c

# Tcaps sources
SRC_SUBDIR		+= libtcaps/srcs
SRCS			+= tcaps_utils.c tcaps_arrow.c tcaps_ctrl_1.c tcaps_ctrl_2.c\
				  tcaps_backspace.c tcaps_tab.c tcaps_size.c tcaps_delete.c\
				  tcaps_moving.c tcaps_home_end.c tcaps_ctrl_arrow.c \
				  tcaps_insert.c tcaps_alt.c tcaps_alt_arrow.c


###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror

#The Directories, Source, Includes, Objects and Libraries
INC			= -I includes
#SRCS_DIR	= srcs
vpath  %c $(SRC_SUBDIR)

#Objects
OBJS_DIR	= objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR	= .deps
DEPS		= $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR	= $(OBJS_DIR) $(DEPS_DIR)

## libft
LIBFT_DIR	= libft
INC			+= -I $(LIBFT_DIR)/includes

## libftprinft
LIBFTPRINTF_DIR	= libftprintf
INC			+= -I $(LIBFTPRINTF_DIR)/includes

## lib_logger
LIBLOGGER_DIR	= liblogger
INC			+= -I $(LIBLOGGER_DIR)/includes

## lib_tcaps
LIBTCAPS_DIR	= libtcaps
INC			+= -I $(LIBTCAPS_DIR)/includes

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

#Doxygen
DOXYGEN := $(shell command -v doxygen 2> /dev/null)

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################
 #########
## RULES ##
 #########
.SECONDARY: $(OBJS)

all: $(NAME)

# Add dependency as prerequisites
-include $(DEPS)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@
	@echo "[\033[35m-----------------------------\033[0m]"
	@echo "[\033[36m------- OK - LIBCBC -------\033[0m]"
	@echo "[\033[35m-----------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
	@$(MKDIR) -p $@

re: clean fclean all

clean:
ifeq ($(shell [ -e $(OBJS_DIR) ] && echo 1 || echo 0),1)
	@echo "\033[35mLIBFTCBC  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
endif
ifeq ($(shell [ -e $(DEPS_DIR) ] && echo 1 || echo 0),1)
	@$(RM) $(DEPS_DIR)
endif

fclean: clean
ifeq ($(shell [ -e $(NAME) ] && echo 1 || echo 0),1)
	@echo "\033[35mLIBFTCBC  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
endif

doc:
ifndef DOXYGEN
	@echo "Please install doxygen first (brew install doxygen)."
else
	@doxygen Doxyfile 1> /dev/null
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m------ Documentation -----\033[0m]"
	@echo "[\033[36m------   generated   -----\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"
endif

.PHONY: re clean fclean all doc
.SUFFIXES: .c .h .o .d
