# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/18 22:40:59 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libtcaps.a

SRCS			= tcaps_utils.c tcaps_arrow.c tcaps_ctrl_1.c tcaps_ctrl_2.c\
				  tcaps_backspace.c tcaps_tab.c tcaps_size.c tcaps_delete.c\
				  tcaps_moving.c tcaps_home_end.c tcaps_ctrl_arrow.c\
				  tcaps_insert.c tcaps_alt.c tcaps_alt_arrow.c tcaps_moving_2.c \
				  tcaps_bell.c tcaps_escape.c tcaps_video.c tcaps_escape_enter.c

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
vpath %c $(SRCS_DIR)

#Objects
OBJS_DIR	= objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR	= .deps
DEPS		= $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR	= $(OBJS_DIR) $(DEPS_DIR)

# Libraries

## libft
LIBFT_DIR	= ../libft
INC			+= -I $(LIBFT_DIR)/includes
LIBS		+= -L $(LIBFT_DIR) -lft

## libftprinft
LIBFTPRINTF_DIR	= ../libftprintf
INC			+= -I $(LIBFTPRINTF_DIR)/includes
LIBS		+= -L $(LIBFTPRINTF_DIR) -lftprintf


LIBLOGGER_DIR	= ../liblogger
INC			+= -I $(LIBLOGGER_DIR)/includes
LIBS		+= -L $(LIBLOGGER_DIR) -llogger

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

#Utils
RM			= rm -rf
MKDIR		= mkdir -p

#Doxygen
DOXYGEN := $(shell command -v doxygen 2> /dev/null)

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

$(NAME): $(OBJS) $(DEPS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@$(ECHOLOR) "[\033[35m---------------------------------\033[0m]"
	@$(ECHOLOR) "[\033[36m-------- Libtcaps Done ! --------\033[0m]"
	@$(ECHOLOR) "[\033[35m---------------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(eval COUNT_OBJ=$(shell echo $$(($(COUNT_OBJ)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT_OBJ) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_P) $<$(C_NO)\n" "[$(PERCENT)%]"

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@
	$(eval COUNT_DEP=$(shell echo $$(($(COUNT_DEP)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT_DEP) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_G) $@$(C_NO)\n" "[$(PERCENT)%]"

$(BUILD_DIR):
	@$(MKDIR) -p $@

re: clean fclean all

clean:
ifeq ($(shell [ -e $(OBJS_DIR) ] && echo 1 || echo 0),1)
	@$(ECHOLOR) "\033[35mLibtcaps  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
endif
ifeq ($(shell [ -e $(DEPS_DIR) ] && echo 1 || echo 0),1)
	@$(ECHOLOR) "\033[35mLibtcaps  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
endif

fclean: clean
ifeq ($(shell [ -e $(NAME) ] && echo 1 || echo 0),1)
	@$(ECHOLOR) "\033[35mLibtcaps  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
endif

doc:
ifndef DOXYGEN
	@echo "Please install doxygen first (brew install doxygen)."
else
	@doxygen Doxyfile 1> /dev/null
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
	@$(ECHOLOR) "[\033[36m------ Documentation -----\033[0m]"
	@$(ECHOLOR) "[\033[36m------   generated   -----\033[0m]"
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
endif

.PHONY: re clean fclean all doc
.SUFFIXES: .c .h .o .d
