# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/02/02 11:51:38 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS_CORE		= ft_atoi.c ft_bzero.c ft_countchiffres.c ft_ctostr.c \
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
ft_wcslen.c ft_wctostr.c ft_wordlen.c ft_wstostr.c

SRCS_GNL		= get_next_line.c

SRCS_FT_PRINTF	= ft_printf.c ft_parse_args.c ft_parse_args2.c utils.c \
printer_s.c printer_d.c printer_o.c printer_p.c printer_u.c printer_x.c \
printer_c.c printer_per.c printer_def.c

SRCS_ARRAY		= array.c array_copy.c array_growth.c array_shrink.c array_setget.c \
array_pushpop.c array_insert.c array_destroy.c array_swap.c

SRCS_STRING		= string.c string_growth.c string_dup.c string_clone.c \
string_insert.c

SRCS_LOGGER		= logger.c logger_utils.c
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
VPATH 		= $(SRCS_DIR)/string $(SRCS_DIR)/array $(SRCS_DIR)/core
VPATH		+= $(SRCS_DIR)/gnl $(SRCS_DIR)/ft_printf $(SRCS_DIR)/logger
#$(DEPS_DIR)/core $(DEPS_DIR)/gnl $(DEPS_DIR)/ft_printf

#Flags, Libraries, Objects and Includes
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/core/%.c, $(SRCS_CORE))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/gnl/%.c, $(SRCS_GNL))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/ft_printf/%.c, $(SRCS_FT_PRINTF))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/array/%.c, $(SRCS_ARRAY))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/string/%.c, $(SRCS_STRING))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/logger/%.c, $(SRCS_LOGGER))
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRCS_DIR)%.c,$(DEPDIR)%.d,$(SRCS))
INC			= -I includes -I includes/gnl

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

#Doxygen
DOXYGEN := $(shell command -v doxygen 2> /dev/null)
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

$(OBJS_DIR)/array/%.o: %.c $(DEPS_DIR)/array/%.d
	@echo "\033[K\033[35mARRAY  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	$(CC-COMMAND)

$(OBJS_DIR)/string/%.o: %.c $(DEPS_DIR)/string/%.d
	@echo "\033[K\033[35mSTRING  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	$(CC-COMMAND)

$(OBJS_DIR)/logger/%.o: %.c $(DEPS_DIR)/logger/%.d
	@echo "\033[K\033[35mSTRING  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	$(CC-COMMAND)

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
.PRECIOUS: $(DEPS_DIR)/core/%.d $(DEPS_DIR)/gnl/%.d $(DEPS_DIR)/ft_printf/%.d \
	$(DEPS_DIR)/array/%.d $(DEPS_DIR)/string/%.d $(DEPS_DIR)/logger/%.d
.SUFFIXES: .c .h .o .d