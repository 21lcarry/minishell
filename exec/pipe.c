#include "../includes/minishell.h"

void	ft_builtin_handler(t_main *main, int i)
{
	if (main->cmd[i]->type == 2)
		ft_echo(main->cmd[i]->command);
	if (main->cmd[i]->type == 4)
		ft_pwd();
	if (main->cmd[i]->type == 5)
		ft_export(main, main->cmd[i]->command, 1);
	if (main->cmd[i]->type == 7)
		ft_env(main);
}

void	ft_exec(t_main *main, int i)
{
	char	**path;

	ft_builtin_handler(main, i);
	if (main->cmd[i]->command[0][0] == '.'
		|| main->cmd[i]->command[0][0] == '/')
		execve(main->cmd[i]->command[0], main->cmd[i]->command, main->env);
	path = ft_get_path(main);
	if (!ft_findcmd_path(main, i, path))
		return ;
	ft_arr_free(path);
	ft_putstr_fd("-minishell: ", STDERR);
	ft_putstr_fd(main->cmd[i]->command[0], STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(strerror(errno), STDERR);
	exit(127);
}

static void	ft_dup(t_main *main, int i, int pipefd[2])
{
	if (main->cmd[i]->fd_out != -1)
		dup2(main->cmd[i]->fd_out, STDOUT);
	else if (i != main->num_p)
		dup2(pipefd[1], STDOUT);
	if (main->cmd[i]->fd_in != -1)
		dup2(main->cmd[i]->fd_in, STDIN);
}

void	ft_init_pipe(t_main *main, int i)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		ft_dup(main, i, pipefd);
		if (main->cmd[i]->command[0][0] != '\0' && main->cmd[i]->error == 0)
			ft_exec(main, i);
		else if (main->cmd[i]->command[0][0] == '\0')
			exit(127);
		else
			exit(0);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(-1, &g_status, 0);
		g_status = WEXITSTATUS(g_status);
		close(pipefd[0]);
	}
}
