# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2016/09/25 18:34:04 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_bzero.c ft_isascii.c ft_memccpy.c ft_memcpy.c ft_strcat.c ft_strcpy.c ft_strncat.c ft_strnstr.c ft_tolower.c \
ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strncmp.c ft_strrchr.c ft_toupper.c \
ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strcmp.c ft_strlen.c ft_strncpy.c ft_strstr.c ft_strlcat.c \
ft_iswhitespace.c ft_atoi.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar.c \
ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_itoa.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_countchiffres.c ft_wordlen.c \
ft_nbword.c ft_freetab.c 

SRCO	=	$(SRC:.c=.o)
HEADERS	=	includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

re: clean fclean all

%.o: %.c
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(CC) -g -o $@ -c $< $(CFLAGS) -I $(HEADERS)

$(NAME): $(SRCO)
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFT  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@ar rc $@ $^
	@ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m------- OK - LIBFT ------\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

clean:
	@echo "\033[35mLIBFT  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)

fclean: clean
	@echo "\033[35mLIBFT  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@rm -f $(NAME)

.PHONY: re clean fclean all