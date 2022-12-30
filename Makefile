SRCS	= 		server.c client.c\

# SRCSB	= 		server_bonus.c client_bonus.c\

OBJS	= 		$(SRCS:.c=.o)

# OBJSB	= 		$(SRCSB:.c=.o)

CC		= 		gcc

CFLAGS	= 		-Wall -Wextra -Werror -g

NAME	=		minitalk

all: 			${NAME}

server: 		server.o
				$(CC) -Lft_printf -lftprintf -o $@ $^

# server_bonus:	server_bonus.o ft_printf/libftprintf.a
# 				$(CC) -o $@ $^

client:			client.o
				$(CC) $^ -o $@ 

# client_bonus:	client_bonus.o ft_printf/libftprintf.a
# 				$(CC) -o $@ $^

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
