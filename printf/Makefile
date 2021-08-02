SRCS		= ft_printf.c src/ft_itoa_base.c src/ft_itoa_un.c src/ft_itoa_unll.c src/ft_write_char.c src/ft_write_hex.c src/ft_write_int.c src/ft_write_percent.c src/ft_write_pointer.c src/ft_write_string.c src/ft_write_unint.c src/ft_write_while.c src/parse.c src/write.c

HEADERS		= includes/ft_printf.h libft/libft.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

NAME		= libftprintf.a

LIBFT 		= ./libft/libft.a

CFLAGS		= -c -Wall -Werror -Wextra


$(NAME):	${OBJS} ${HEADERS}
			$(MAKE) bonus -C ./libft
			cp libft/libft.a ${NAME}
			${CC} ${CFLAGS} ${HEADERS} ${SRCS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			$(MAKE) clean -C ./libft
			${RM} ${OBJS}
			${RM} *.o

fclean:		clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re