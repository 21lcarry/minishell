#ifndef MINISHELL_H
# define MINISHELL_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../printf/includes/ft_printf.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define PIP 30
# define SP 31
# define IN 29
# define OUT 28
int g_status;

typedef struct s_cmd
{
    int fd_in;
    int fd_out;
    int error;
    unsigned char type;
    char *h_doc;
    char *file;
    char **command;
    char *tmp;
    int m;
}   t_cmd;

typedef struct s_main
{
    char **env;
    char *line;
    int stop;
    int num_p;
    t_cmd **cmd;
    int tmp_in;
    int tmp_out;
    char **env_exp;
}   t_main;

/*init*/
int ft_init_struct(t_main *main, char **ev);

/*signal*/
void ft_sigint(int param);

/*parsing*/
int ft_start(t_main *main);
int ft_preparser(t_main *main);
int ft_check_other(t_main *main);
int ft_check_pipe(char *line, int *i);
int ft_check_quote(char *line, int *i);
int ft_lexer(t_main *main);
void ft_lex_space(t_main *main, int *i);
char *ft_lex_find_var(t_main *main, int j, int i);
int ft_lex_dquote(t_main *main, int *i);
int ft_lex_quote(t_main *main, int *i);
int ft_lex_var(t_main *main, int *i);
void ft_lex_dquote2(t_main *main, int i, int j);
void ft_lex_var2(t_main *main, char *var, int *i, int j);
int ft_count_pipes(t_main *main);
void ft_init_cmd(t_main *main);
int ft_fill_fd_newtmp(t_main *main, int tmp_i, int *i, int j);
char *ft_read_hdoc(char *key);
int ft_fill_fd(t_main *main, int *i, int j);
int ft_fd_close(t_main *main, int j);
int ft_fill_fd_din(t_main *main, int *i, int j);
int ft_fill_fd_in(t_main *main, int *i, int j);
int ft_fill_fd_out(t_main *main, int *i, int j);
int ft_fill_fd_dout(t_main *main, int *i, int j);
char	*ft_strtrim2(char const *s1, char const *set);
int ft_parser(t_main *main);
int ft_parse_cmd(t_main *main, int i, int *j);
int ft_fill_cmd(t_main *main, int j);
void ft_fill_command(t_main *main, int j);
void	ft_printerr_fd(char *path);
int ft_lexer_part(t_main *main, int i);
void	ft_parseerr(t_main *main, int j);

/*execute*/
int		ft_pwd(void);
int ft_export(t_main *main, char **cmd, int flag);
void ft_env(t_main *main);
void ft_echo(char **cmd);
int ft_cd(t_main *main, char **cmd);
void ft_add_env(char *key, t_main *main, char *str);
void ft_add_env2(char *key, t_main *main, char *str);
char *ft_getenv(char *key, t_main *main);
int ft_unset(t_main *main, char **cmd);
int ft_del_env_exp(char *key, t_main *main);
void ft_add_env_exp(char *key, t_main *main, char *str);
void ft_add_env_exp2(char *key, t_main *main, char *str);
char *ft_get_export_str(char *str);
void	ft_add_by_key(t_main *main, char *cmd, int j);
int ft_del_env_exp(char *key, t_main *main);
int ft_del_env_exp2(t_main *main, int i);
int ft_del_env(char *key, t_main *main);
int ft_del_env2(t_main *main, int i);
int ft_builtin_exit(char **cmd);
void ft_init_pipe(t_main *main, int i);
void	ft_exec(t_main *main, int i);
void ft_builtin_handler(t_main *main, int i);
int	ft_execute(t_main *main);

/*utils*/
int ft_free_cmd(t_main *main);
void	ft_putstr_fd(char *s, int fd);
void	ft_arr_free(char **arr);
void ft_close(int fd);
char **ft_get_path(t_main *main);
int ft_findcmd_path(t_main *main, int i, char **path);
int	ft_preparser_error(char c);
int	ft_lexer_error(void);
void	ft_shell_lvl(t_main *main);
char	*ft_getenv(char *key, t_main *main);
void	ft_check_type(t_main *main);


#endif