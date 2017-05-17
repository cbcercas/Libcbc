# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/17 16:00:07 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libcbc.a

## libft
LIBFT_DIR			= ./libft_cbc
LIBFT_FILE			= $(LIBFT_DIR)/libftcbc.a

## libftprinft
LIBFTPRINTF_DIR		= ./libftprintfcbc
LIBFTPRINTF_FILE	= $(LIBFTPRINTF_DIR)/libftprintf.a

## lib_logger_cbc
LIBLOGGER_DIR		= ./lib_logger_cbc
LIBLOGGER_FILE		= $(LIBLOGGER_DIR)/liblogger.a

## lib_tcaps
LIBTCAPS_DIR		= ./lib_tcaps
LIBTCAPS_FILE		= $(LIBTCAPS_DIR)/libtcaps.a

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

ifeq ($(WITH_LIBFT),yes)
	LIBS	+= $(LIBFT_FILE)
endif

ifeq ($(WITH_FTPRINTF),yes)
	LIBS	+= $(LIBFTPRINTF_FILE)
endif

ifeq ($(WITH_LOGGER),yes)
	LIBS	+= $(LIBLOGGER_FILE)
endif

ifeq ($(WITH_TCAPS),yes)
	LIBS	+= $(LIBTCAPS_FILE)
endif

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

all: $(NAME)

$(NAME): libs $(LIBS)
	ar -rcT $(NAME) $(LIBS)
	ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m----- OK - LIBCBBC -----\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

libs:
ifeq ($(WITH_LOGGER),yes)
	@make -C $(LIBLOGGER_DIR)
endif
ifeq ($(WITH_FTPRINTF),yes)
	@make -C $(LIBFTPRINTF_DIR)
endif
ifeq ($(WITH_LIBFT),yes)
	@make -C $(LIBFT_DIR)
endif
ifeq ($(WITH_TCAPS),yes)
	@make -C $(LIBTCAPS_DIR)
endif

re: clean fclean all

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBFTPRINTF_DIR)
	@make clean -C $(LIBLOGGER_DIR)
	@make clean -C $(LIBTCAPS_DIR)

fclean: clean
ifeq ($(shell [ -e $(NAME) ] && echo 1 || echo 0),1)
	@echo "\033[35mLIBCBC  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
endif
	@make fclean -C $(LIBTCAPS_DIR)
	@make fclean -C $(LIBLOGGER_DIR)
	@make fclean -C $(LIBFTPRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)

.PHONY: re clean fclean all libs
.SUFFIXES: .a
