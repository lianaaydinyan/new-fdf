NAME = fdf
CC = cc
CFLAGS =-Wall -Wextra -Werror
SRC = $(wildcard  ./src/*.c)
OBJ = $(SRC:.c=.o)
LOBI = ./libb/libft.a

all : lala $(NAME)

lala :
	@make -C ./libb

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LOBI) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@make -C ./libb clean
	rm -rf $(OBJ)

fclean : clean
	@make -C ./libb fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all , re , clean, fclean