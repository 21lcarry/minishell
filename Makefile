SRCS		= main.c main_utils.c signal.c init.c parser/preparser.c parser/preparser2.c parser/lexer.c parser/lexer2.c parser/fd_handler_utils.c parser/fd_handler.c parser/fd_handler2.c parser/parse_utils.c parser/parse.c builtin/ft_echo.c builtin/ft_env.c builtin/ft_export.c builtin/ft_pwd.c builtin/ft_cd.c builtin/ft_unset.c builtin/ft_export2.c builtin/ft_unset2.c builtin/ft_exit.c exec/pipe.c exec/pipe_utils.c exec/exec_utils.c exec/type.c
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