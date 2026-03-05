CC			= cc
NAME_SERVER	= server
NAME_CLIENT	= client
SRC_SERVER	= server.c
SRC_CLIENT	= client.c
OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
HEADER		= minitalk.h
CFLAGS		= -Werror -Wall -Wextra -g
PRINTF 		= ft_printf/libftprintf.a
LIBFT		= libft/libft.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(PRINTF) $(LIBFT)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(PRINTF) $(LIBFT)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	@rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@rm -rf $(NAME_CLIENT) $(NAME_SERVER)

.PHONY: all re clean fclean
