# Executable name
NAME	= gnl

# Source files
SRC		= get_next_line.c main.c

LIBFT_SRC = ft_strchr.c ft_putstr.c ft_strlen.c ft_strsub.c ft_strnew.c \
			ft_strncpy.c ft_putstr_fd.c ft_bzero.c ft_memset.c

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
I_LIB		= -Ilibft
LIB			= -L$(LIB_DIR) $(I_LIB) -lft
OBJ			= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
LIB_FILE	= $(LIB_DIR)/libft.a
INC			= -I$(INC_DIR) -I$(LIB_DIR)

#Utils
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

$(NAME): $(LIB_FILE) $(OBJ)
	$(CC) $(CC_FLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/get_next_line.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(LIB)

$(LIB_FILE):
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(SRC_DIR)/$(SRC)
	norminette $(INC_DIR)/*.h

.PHONY: clean fclean re norme init $(LIB_FILE)
