# Executable name
NAME		= libftprintf.a

# Source files
SRCS		= ft_printf.c ft_parse_args.c utils.c \
				printer_s.c \
				printer_d.c \
				printer_i.c \
				printer_o.c \
				printer_p.c \
				printer_u.c \
				printer_x.c \
				printer_c.c \
				printer_per.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC				= clang

#The Directories, Source, Includes, Objects and Libraries
SRC_DIR			= sources
INC_DIR			= includes 
OBJ_DIR			= objects
LIB_DIR			= libft
LIBFT_INC_DIR	= libft/includes

#Flags, Libraries, Objects and Includes
CFLAGS			= -Wall -Wextra -Werror -g
I_LIB			= -Ilibftprintf
LIB				= -L$(LIB_DIR) $(I_LIB)
OBJS			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
SRC_FILES		= $(patsubst %.c,$(SRC_DIR)/%.c,$(SRCS))
LIBFT_FILE		= libft/libft.a
LIB_FILE		= libftprintf.a
INC				= -I $(INC_DIR) -I $(LIBFT_INC_DIR)

#Utils
CP				= cp
RM				= rm -f
MKDIR			= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################

all: init $(NAME)

init:
	@$(MKDIR) $(SRC_DIR) $(OBJ_DIR) $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(LIBFT_FILE) $(OBJS)
	@echo "\033[K\033[35mLIBFT  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFTPRINTF  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@ar rc $@ $^
	@ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m---- OK - LIBFTPRINTF ----\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

$(LIBFT_FILE):
	@make -C libft

test: all
	@$(CC) $(CFLAGS) -o test $(SRC_DIR)/main.c $(LIB_FILE) $(INC) 

clean:
	@echo "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	@echo "\033[35mLIBFTPRINTF  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

norme:
	norminette $(SRC_DIR)/$(SRC)
	norminette $(INC_DIR)/*.h

.PHONY: all clean fclean re norme init $(LIB_FILE)
