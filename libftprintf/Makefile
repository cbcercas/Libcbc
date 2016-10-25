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
				printer_per.c \
				printer_def.c

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
LIBFT_DIR		= libft
LIBFT_INC_DIR	= libft/includes

#Flags, Libraries, Objects and Includes
CFLAGS			= -Wall -Wextra -Werror -g
LIB				= -L. -lftprintf
OBJS			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
LIBFT_FILE		= libft/libft.a
INC				= -I $(INC_DIR) -I $(LIBFT_INC_DIR)

#Utils
CP				= cp
RM				= rm -rf
MKDIR			= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(MKDIR) $(SRC_DIR) $(OBJ_DIR) $(INC_DIR)
	@echo "\033[K\033[35mLIBFTPRINTF  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(LIBFT_FILE) $(OBJS)
	@echo "\033[K\033[35mLIBFTPRINTF  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFTPRINTF  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@cp $(LIBFT_FILE) $(NAME)
	@ar r $@ $^
	@ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m---- OK - LIBFTPRINTF ----\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR)

test: all
	$(CC) $(CFLAGS) -o test $(SRC_DIR)/main.c $(LIB) $(INC)

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

chkforbidden:
	@grep -r stdio.h .
	@grep -r "printf" . | grep -v "ft_printf"
	@grep -r "//" .

rendu: fclean
	@$(RM) subject
	@mv libft libft.back
	@git submodule deinit libft
	@git rm libft
	@mv libft.back libft
	@git add libft
	@git commit -m "clean rendu"

.PHONY: all $(NAME) clean fclean re norme chkforbidden rendu
.SUFFIXES:
