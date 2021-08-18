SRCS		= main.c signal.c init.c

HEADERS		= includes/minishell.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

NAME		= minishell

LIBFT 		= ./printf/libftprintf.a


CFLAGS		= -c -Wall -Werror -Wextra


$(NAME):	${OBJS} ${HEADERS}
			$(MAKE) -C printf all
			$(CC) $(OBJS) $(READLINE) $(LIBFT) -lreadline $(HEADERS)  -o $(NAME)

all:		${NAME}

clean:
			$(MAKE) -C printf clean
			${RM} ${OBJS}
			${RM} *.o

fclean:		clean
			$(MAKE) -C printf fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re