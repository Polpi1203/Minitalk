NAME	= libft.a

SRCS	= $(wildcard *.c)

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) 
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all