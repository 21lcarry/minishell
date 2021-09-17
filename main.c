#include "includes/minishell.h"

static void	ft_err(t_main *main, int err)
{
	if (err != -1)
	{
		ft_putstr_fd("-minishell: ", STDERR);
		ft_putstr_fd(main->cmd[err]->command[0], STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
	}
}

int	ft_start(t_main *main)
{
	int	index;
	int	err;

	err = -2;
	index = 0;
	if (main->line[0] != '\0')
	{
		index = ft_preparser(main);
		if (index != -1)
			err = ft_preparser_error(main->line[index]);
		else if (!ft_lexer(main))
			err = ft_lexer_error();
		else
			ft_parser(main);
		if (err == -2 && index == -1)
		{
			err = ft_execute(main);
			if (err == -3)
				return (-1);
			ft_err(main, err);
		}
	}
	if (index == -1)
		return (ft_free_cmd(main));
	return (0);
}

int	main(int ac, char **av, char **ev)
{
	t_main	*main;

	(void)ac;
	(void)av;
	main = (t_main *)malloc(sizeof(t_main));
	ft_init_struct(main, ev);
	ft_shell_lvl(main);
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	main->line = readline("minishell$ ");
	while (main->line != NULL && main->stop >= 0)
	{
		if (*main->line != '\0')
			add_history(main->line);
		main->stop = ft_start(main);
		if (main->stop < 0)
			break ;
		free(main->line);
		main->line = readline("minishell$ ");
	}
	if (main->stop >= 0)
		ft_putendl_fd("exit", STDERR);
	exit(g_status);
}
