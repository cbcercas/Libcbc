# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/02/06 03:20:46 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft-test

SRCS_MAIN		=

SRCS_ARRAY		= test_array_create.c test_array_simple_usage.c

SRCS_STRING		= test_string_create.c test_string_dup.c test_string_clone.c \
test_string_insert.c test_string_join.c test_string_remove.c \
test_string_shrink.c

SRCS_LOGGER		= test_logger.c
###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

#The Directories, Source, Includes, Objects and Libraries
SRCS_DIR	= srcs
OBJS_DIR	= objs
DEPS_DIR	= .deps
LIBFT_DIR	= ../
VPATH 		= $(SRCS_DIR) $(SRCS_DIR)/array $(SRCS_DIR)/string

#Flags, Libraries, Objects and Includes
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/%.c, $(SRCS_MAIN))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/array/%.c, $(SRCS_ARRAY))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/string/%.c, $(SRCS_STRING))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/logger/%.c, $(SRCS_LOGGER))
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRCS_DIR)%.c,$(DEPDIR)%.d,$(SRCS))
LIBFT_FILE	= $(LIBFT_DIR)/libft.a
INC			= -I includes
## libft includes
INC			+= -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/includes/ft_printf -I $(LIBFT_DIR)/includes/gnl
# criterion includes
INC			+= -I ../../Criterion/include

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

# Commande
define CC-COMMAND
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
endef

define DEPS-COMMAND
	@$(CC) $(CFLAGS) $(INC) -MM -MT $(DEPS_DIR)/$(patsubst %.c,$(DEPS_DIR)/%.d, $(notdir $@)) $< -MF $@
endef

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################

 ##############################
##  AUTO DEPENDENCY GENERATOR ##
 ##############################

$(DEPS_DIR)/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/array/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/string/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/logger/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

# Add dependency as prerequisites
-include $(DEPS)

 ##################################
##  END AUTO DEPENDENCY GENERATOR ##
 ##################################

 #########
## RULES ##
 #########

all: $(NAME)

re: clean fclean all

$(OBJS_DIR)/%.o: %.c $(DEPS_DIR)/%.d
	@echo "\033[K\033[35mLibft-test-main  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/array/%.o: %.c $(DEPS_DIR)/array/%.d
	@echo "\033[K\033[35mLibft-test-array  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/string/%.o: %.c $(DEPS_DIR)/string/%.d
	@echo "\033[K\033[35mLibft-test-string  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/logger/%.o: %.c $(DEPS_DIR)/logger/%.d
	@echo "\033[K\033[35mLibft-test-logger  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(NAME): $(LIBFT_FILE) $(OBJS)
	@echo "\033[K\033[35mLibft-test  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFT-test  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L ../../Criterion/build -lcriterion $(INC)
	@echo "[\033[35m---------------------------------\033[0m]"
	@echo "[\033[36m------- Libft Test Done ! -------\033[0m]"
	@echo "[\033[35m---------------------------------\033[0m]"

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR)

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

.PHONY: re clean fclean all
.PRECIOUS: $(DEPS_DIR)/%.d $(DEPS_DIR)/array/%.d $(DEPS_DIR)/string/%.d $(DEPS_DIR)/logger/%.d
.SUFFIXES: .c .h .o .d
