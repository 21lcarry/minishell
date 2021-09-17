#include "includes/minishell.h"

int  ft_init_struct(t_main *main, char **ev)
{
	g_status = 0;
	main->env = ft_arrdup(ev);
	main->line = NULL;
	main->stop = 0;
	main->num_p = 0;
	main->cmd = NULL;
	main->tmp_in = dup(0);
	main->tmp_out =	dup(1);
	main->env_exp = ft_arrdup(ev);
	ft_del_env_exp("_", main);
	return(1);
}

void ft_init_cmd(t_main *main)
{
	int i;

	main->cmd = (t_cmd **)malloc((main->num_p + 2) * sizeof(t_cmd *));
	i = -1;
	while (++i <= main->num_p)
	{
		main->cmd[i] = (t_cmd *)malloc(sizeof(t_cmd));
		main->cmd[i]->fd_in = -1;
		main->cmd[i]->fd_out = -1;
		main->cmd[i]->h_doc = NULL;
		main->cmd[i]->command = NULL;
		main->cmd[i]->tmp = NULL;
		main->cmd[i]->error = 0;
		main->cmd[i]->type = 0;
		main->cmd[i]->m = 0;
		main->cmd[i]->file = NULL;
	}
	main->cmd[main->num_p + 1] = NULL;
}