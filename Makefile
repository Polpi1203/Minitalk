SRCS	= 		server.c client.c\

OBJS	= 		$(SRCS:.c=.o)

CC		= 		gcc

CFLAGS	= 		-Wall -Wextra -Werror -g

NAME	=		minitalk

all: 			${NAME}

server: 		server.o
				$(CC) -Lft_printf -lftprintf -o $@ $^

client:			client.o
				$(CC) -Lft_printf -lftprintf -o $@ $^ 

%.o: 			%.c
				$(CC) $? -c $(CFLAGS)

${NAME}:		ft_printf/libftprintf.a server client 

ft_printf/libftprintf.a:
				@make -C ft_printf

clean:
				rm -f $(OBJS)
				@make -C ft_printf clean
 
fclean:			clean
					${RM} ${NAME}
					@make -C ft_printf fclean

re: 			fclean all

.PHONY:			all  clean fclean re
