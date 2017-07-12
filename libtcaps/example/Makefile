# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/03/27 11:19:16 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= test.e

SRCS			+= main.c

SRC_SUBDIR		+= exec
SRCS			+= tcaps_key_exec.c tcaps_exec_ctrl_1.c tcaps_exec_ctrl_2.c\
                    tcaps_exec_arrow.c tcaps_exec_delete.c tcaps_exec_tab.c\
                    tcaps_exec_ctrl_arrow.c tcaps_exec_home_end.c\
                    tcaps_exec_insert.c tcaps_exec_alt.c

SRC_SUBDIR		+= term
SRCS			+= term_modes.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################
#  Compiler
CC				= clang
CFLAGS			= -Wall -Wextra -Werror

# Sources
SRCS_DIR		= srcs
vpath %.c $(SRCS_DIR)
vpath %.c $(addprefix $(SRCS_DIR)/,$(SRC_SUBDIR))

#Objects
OBJS_DIR		= objs
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR		= .deps
DEPS			= $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR		= $(OBJS_DIR) $(DEPS_DIR) bin

## lib_logger
LIBLOGGER_DIR	= ../../liblogger
INC			+= -I $(LIBLOGGER_DIR)/includes

## libftprinft
LIBFTPRINTF_DIR	= ../../libftprintf
INC			+= -I $(LIBFTPRINTF_DIR)/includes


## libft
LIBFT_DIR	= ../../libft
INC			+= -I $(LIBFT_DIR)/includes

LIBCBC_DIR	= ../..
LIBS        += -L $(LIBCBC_DIR) -lcbc

INC         += -I includes

# Libraries
## Libtcaps
LIBTCAPS_DIR	= ..
INC				+= -I $(LIBTCAPS_DIR)/includes

## Curses
LIBS				+= -lcurses

#Utils
RM				= rm -rf
MKDIR			= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################
 #########
## RULES ##
 #########
.SECONDARY: $(OBJS) libs

all: $(DEPS) $(NAME)

# Add dependency as prerequisites
-include $(DEPS)

$(NAME): $(OBJS) libs | bin
	@$(CC) $(CFLAGS) -o bin/$(NAME) $(OBJS) $(INC) $(LIBS)
	@echo "[\033[35m---------------------------------\033[0m]"
	@echo "[\033[36m-------- Minishell Done ! -------\033[0m]"
	@echo "[\033[35m---------------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
	@$(MKDIR) -p $@

libs:
	@make -C $(LIBCBC_DIR)

re: clean fclean all

clean:
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBTCAPS_DIR)

fclean: clean
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIBCBC_DIR)


.PHONY: re clean fclean all libs
.SUFFIXES: .c .h .o .d
