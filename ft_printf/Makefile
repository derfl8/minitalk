CC      = cc
CFLAGS  = -Werror -Wextra -Wall
NAME    = libftprintf.a
HEADER  = ft_printf.h

SRCS    = \
ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_strlen.c \
ft_itoa.c \
ft_puthexl.c \
ft_puthexh.c \
ft_putptr.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
