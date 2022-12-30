NAME 	= 	libftprintf.a

SRCS 	= 	$(wildcard *.c)

OBJS	=	${SRCS:.c=.o}

LIBFT	=	libft

CC		=	gcc

RM		= 	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}
		@make clean -C ${LIBFT}

fclean: clean
		${RM} ${NAME}
		@$(RM) -f $(LIBFT)/libft.a

re: fclean all