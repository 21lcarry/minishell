#include "includes/minishell.h"

void ft_history(char *line)
{
	(void)line;
}

int ft_start(t_main *main)
{
	(void)main;
	return (0);
}

int main(int ac, char **av, char **ev)
{
	t_main *main;

	(void)ac;
	(void)av;
	main = ft_init_struct(ev);
	if (main == NULL)
		return (ft_printf("malloc error\nexit\n"));
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	main->line = readline("minishell$ ");
	while (main->line != NULL && main->stop >= 0)
	{
		if (*main->line != '\0')
			ft_history(main->line);
		main->stop = ft_start(main);
		if (main->stop < 0)
			break ;
		free(main->line);
		main->line = readline("minishell$ ");
		if (main->line)
			printf("%s\n", main->line);
	}
	free(main);
	printf("exit\n");
	return (0);//main_end(str, res));
}