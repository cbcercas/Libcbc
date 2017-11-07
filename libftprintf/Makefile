# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/17 13:26:13 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC_SUBDIR		+= ft_printf
SRCS			+= ft_printf.c ft_printf_2.c ft_parse_args.c ft_parse_args2.c \
					utils.c printer_s.c printer_d.c printer_o.c printer_p.c \
					printer_u.c printer_x.c printer_c.c printer_per.c \
					printer_def.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC			= clang
CFLAGS		= -g -Wall -Wextra -Werror

#The Directories, Source, Includes, Objects and Libraries
INC			= -I includes
SRCS_DIR	= srcs
vpath  %c $(addprefix $(SRCS_DIR)/,$(SRC_SUBDIR))

#Objects
OBJS_DIR	= objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR	= .deps
DEPS		= $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR	= $(OBJS_DIR) $(DEPS_DIR)

## libft
LIBFT_DIR	= ../libft_cbc
INC			+= -I $(LIBFT_DIR)/includes
LIBS		+= -L $(LIBFT_DIR) -lft

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

COUNT_OBJ = 0
COUNT_DEP = 0
TOTAL = 0
PERCENT = 0

$(eval TOTAL=$(shell echo $$(printf "%s" "$(SRCS)" | wc -w)))

#color
C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m 
C_B = \033[1;34m 
C_C = \033[1;36m
C_R = \033[1;31m
C_P = \033[1;35m 

DOXYGEN = $(shell doxygen -v dot 2> /dev/null)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	ECHOLOR = echo -e
endif
ifeq ($(UNAME_S), Darwin) 
	ECHOLOR = echo
endif

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

$(NAME): $(OBJS) libs
	@ar rc $@ $(OBJS)
	@ranlib $@
	@$(ECHOLOR) "[\033[35m----------------------------\033[0m]"
	@$(ECHOLOR) "[\033[36m----- OK - LIBFTPRINTF -----\033[0m]"
	@$(ECHOLOR) "[\033[35m----------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(eval COUNT_OBJ=$(shell echo $$(($(COUNT_OBJ)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT_OBJ) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_P) $<$(C_NO)\n" "[$(PERCENT)%]"

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@
	$(eval COUNT_DEP=$(shell echo $$(($(COUNT_DEP)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT_DEP) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_G) $@$(C_NO)\n" "[$(PERCENT)%]

$(BUILD_DIR):
	@$(MKDIR) -p $@

libs:
	@make -C $(LIBFT_DIR)

re: clean fclean all

clean:
ifeq ($(shell [ -e $(OBJS_DIR) ] && echo 1 || echo 0),1)
	@$(ECHOLOR) "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
endif
ifeq ($(shell [ -e $(DEPS_DIR) ] && echo 1 || echo 0),1)
	@$(RM) $(DEPS_DIR)
endif
	@make fclean -C $(LIBFT_DIR)

fclean: clean
ifeq ($(shell [ -e $(NAME) ] && echo 1 || echo 0),1)
	@$(ECHOLOR) "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
endif
	@make fclean -C $(LIBFT_DIR)

doc:
ifndef DOXYGEN
	@$(ECHOLOR) "Please install doxygen first (brew install doxygen)."
else
	@doxygen Doxyfile 1> /dev/null
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
	@$(ECHOLOR) "[\033[36m------ Documentation -----\033[0m]"
	@$(ECHOLOR) "[\033[36m------   generated   -----\033[0m]"
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
endif

.PHONY: re clean fclean all doc
.SUFFIXES: .c .h .o .d
