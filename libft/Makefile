# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/01/15 18:53:07 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS_CORE		=	ft_bzero.c ft_isascii.c ft_memccpy.c ft_memcpy.c ft_strcat.c ft_strcpy.c ft_strncat.c ft_strnstr.c ft_tolower.c \
ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strncmp.c ft_strrchr.c ft_toupper.c \
ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strcmp.c ft_strlen.c ft_strncpy.c ft_strstr.c ft_strlcat.c \
ft_iswhitespace.c ft_atoi.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar.c \
ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_itoa.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_countchiffres.c ft_wordlen.c \
ft_nbword.c ft_freetab.c ft_putnstr.c ft_wcslen.c ft_putwstr.c ft_uitobase.c ft_imtoa.c ft_uitooctal.c ft_uitohex.c \
ft_putwchar.c ft_strrev.c ft_strjoincl.c ft_ctostr.c ft_wctostr.c ft_wstostr.c

SRCS_GNL		= get_next_line.c

SRCS_FT_PRINTF	= ft_printf.c ft_parse_args.c utils.c printer_s.c printer_d.c \
printer_o.c printer_p.c printer_u.c printer_x.c printer_c.c printer_per.c printer_def.c

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
VPATH 		= $(SRCS_DIR)/core $(SRCS_DIR)/gnl $(SRCS_DIR)/ft_printf
#$(DEPS_DIR)/core $(DEPS_DIR)/gnl $(DEPS_DIR)/ft_printf

#Flags, Libraries, Objects and Includes
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/core/%.c, $(SRCS_CORE))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/gnl/%.c, $(SRCS_GNL))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/ft_printf/%.c, $(SRCS_FT_PRINTF))
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRCS_DIR)%.c,$(DEPDIR)%.d,$(SRCS))
INC			= -I includes -I includes/ft_printf -I includes/gnl

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

$(DEPS_DIR)/core/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/gnl/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/ft_printf/%.d: %.c
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

$(OBJS_DIR)/core/%.o: %.c $(DEPS_DIR)/core/%.d
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/gnl/%.o: %.c $(DEPS_DIR)/gnl/%.d
	@echo "\033[K\033[35mGNL  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/ft_printf/%.o: %.c $(DEPS_DIR)/ft_printf/%.d
	@echo "\033[K\033[35mFT_PRINTF  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(NAME): $(OBJS)
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFT  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m------- OK - LIBFT -------\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

clean:
	@echo "\033[35mLIBFT  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mLIBFT  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)

fclean: clean
	@echo "\033[35mLIBFT  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)

.PHONY: re clean fclean all
.PRECIOUS: $(DEPS_DIR)/core/%.d $(DEPS_DIR)/gnl/%.d $(DEPS_DIR)/ft_printf/%.d
.SUFFIXES: .c .h .o .d