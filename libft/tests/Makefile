# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/02/13 12:06:25 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft-test

SRCS		=

SRC_SUBDIR	+= array
SRCS		+= test_array_create.c test_array_simple_usage.c

SRC_SUBDIR	+= string
SRCS		+= test_string_create.c test_string_dup.c test_string_clone.c \
test_string_insert.c test_string_join.c test_string_remove.c \
test_string_shrink.c test_string_replace.c

SRC_SUBDIR	+= logger
SRCS		+= test_logger.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################
#  Compiler
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

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

# Libraries
LIBFT_DIR	= ../
LIBFT_FILE	= $(LIBFT_DIR)libft.a
INC			= -I includes
## libft includes
INC			+= -I $(LIBFT_DIR)includes
## criterion includes
INC			+= -I ../../Criterion/include

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################
 #########
## RULES ##
 #########
.SECONDARY: $(OBJS) lib

all: $(DEPS) $(NAME)

# Add dependency as prerequisites
-include $(DEPS)

$(NAME): $(OBJS) lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L ../../Criterion/build -lcriterion $(INC)
	@echo "[\033[35m---------------------------------\033[0m]"
	@echo "[\033[36m------- Libft Test Done ! -------\033[0m]"
	@echo "[\033[35m---------------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
	@$(MKDIR) -p $@

lib:
	@make -C $(LIBFT_DIR)

re: clean fclean all

clean:
	@echo "\033[35mLibft-test  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mlibft-test  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "\033[35mLibft-test  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

.PHONY: re clean fclean all lib
.SUFFIXES: .c .h .o .d
