#ifndef MINISHELL_H
# define MINISHELL_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../printf/includes/ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_main
{
    char *line;
    int stop;
}   t_main;

/*init*/
t_main  *ft_init_struct(char **ev);

/*signal*/
void ft_sigint(int param);

/*parsing*/
int ft_start(t_main *main);

#endif