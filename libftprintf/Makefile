# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/15 00:22:07 by chbravo-         ###   ########.fr        #
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
LIBFT_DIR	= ../Libft_corrige
INC			+= -I $(LIBFT_DIR)/includes
LIBS		+= -L $(LIBFT_DIR) -lft

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

all: $(DEPS) $(NAME)

# Add dependency as prerequisites
-include $(DEPS)

$(NAME): $(OBJS) libs
	ar rc $@ $(OBJS)
	ranlib $@
	@echo "[\033[35m----------------------------\033[0m]"
	@echo "[\033[36m----- OK - LIBFTPRINTF -----\033[0m]"
	@echo "[\033[35m----------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
	@$(MKDIR) -p $@

libs:
	make -C $(LIBFT_DIR)

re: clean fclean all

clean:
	@echo "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	@echo "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

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