# Executable name
NAME	= libftprintf.a

# Source files
SRC		= ft_printf.c ft_parse_args.c utils.c \
			printer_s.c \
			printer_S.c \
			printer_d.c \
			printer_i.c \
			printer_o.c \
			printer_O.c \
			printer_p.c \
			printer_u.c \
			printer_x.c \
			printer_X.c \
			printer_c.c \
			printer_C.c \
			printer_per.c

LIBFT_SRC = ft_strchr.c ft_putstr.c ft_strlen.c ft_strsub.c ft_strnew.c \
			ft_strncpy.c ft_putstr_fd.c ft_bzero.c ft_memset.c ft_putnstr.c \
			ft_putnstr_fd.c ft_isdigit.c ft_putchar.c ft_putchar_fd.c \
			ft_putwchar.c ft_putwchar_fd.c ft_putwstr_fd.c ft_putwstr.c \
			ft_wcslen.c ft_putnbr.c ft_countchiffres.c ft_strnew.c \
			ft_sttoa.c ft_imtoa.c ft_ltoa.c ft_lltoa.c ft_itoa.c ft_stoa.c \
			ft_strrev.c ft_pow.c ft_strcpy.c ft_uitobase.c ft_uitohex.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC			= gcc

#The Directories, Source, Includes, Objects and Libraries
SRC_DIR		= source
INC_DIR		= include 
OBJ_DIR		= object
LIB_DIR		= libft

#Flags, Libraries, Objects and Includes
CFLAGS		= -Wall -Wextra -Werror -g
I_LIB		= -Ilibftprintf
LIB			= -L$(LIB_DIR) $(I_LIB)
OBJ_PRINTF	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_LIBFT	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIBFT_SRC))
LIB_FILE	= libftprintf.a
INC			= -I$(INC_DIR) -I$(LIB_DIR)

#Utils
CP			= cp
RM			= rm -f
MKDIR		= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################

all: $(init) $(NAME)

init:
	@$(MKDIR) $(SRC_DIR) $(OBJ_DIR) $(INC_DIR) $(LIB_DIR)


$(NAME): $(OBJ_LIBFT) $(OBJ_PRINTF)
	ar rc $(NAME) $(OBJ_PRINTF) $(OBJ_LIBFT)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/libftprintf.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -o $@ -c $<

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c libft/libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(SRC_DIR)/main.c $(LIB_FILE)
	$(CC) $(CFLAGS) -o test $(SRC_DIR)/main.c $(LIB_FILE) $(INC) 

clean:
	$(RM) $(OBJ_PRINTF)
	$(RM) $(OBJ_LIBFT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(SRC_DIR)/$(SRC)
	norminette $(INC_DIR)/*.h

.PHONY: clean fclean re norme init $(LIB_FILE)
