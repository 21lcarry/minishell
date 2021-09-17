#include "../includes/minishell.h"

static int	ft_cd_error(char **args)
{
	ft_putstr_fd("-minishell: cd: ", STDERR);
	ft_putstr_fd(strerror(errno), STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(args[1], STDERR);
	return (1);
}

static int	ft_go_home(t_main *main)
{
	char	*home;
	char	*newpwd;

	home = getenv("HOME");
	if (!home)
	{
		g_status = 1;
		ft_putendl_fd("-minishell : cd: HOME not set", STDERR);
		return (-1);
	}
	newpwd = getenv("PWD");
	ft_add_env("OLDPWD=", main, newpwd);
	ft_add_env_exp("OLDPWD=", main, newpwd);
	if (chdir(home) == 0)
	{
		ft_add_env("PWD=", main, home);
		ft_add_env_exp("PWD=", main, home);
	}
	return (-1);
}

static int	ft_go_back(t_main *main)
{
	char	*path;
	char	*newpwd;

	path = ft_getenv("OLDPWD", main);
	if (!path)
	{
		ft_putendl_fd("-minishell : cd: OLDPWD not set", STDERR);
		return (1);
	}
	newpwd = ft_getenv("PWD", main);
	ft_add_env("OLDPWD=", main, newpwd);
	ft_add_env_exp("OLDPWD=", main, newpwd);
	if (newpwd)
		free(newpwd);
	if (chdir(path) == 0)
	{
		ft_add_env("PWD=", main, path);
		ft_add_env_exp("PWD=", main, path);
	}
	ft_putendl_fd(path, STDOUT);
	free(path);
	return (0);
}

static void	ft_upd_pwd(t_main *main)
{
	char	*newpwd;
	char	cwd[4096];

	newpwd = ft_getenv("PWD=", main);
	ft_add_env("OLDPWD=", main, newpwd);
	ft_add_env_exp("OLDPWD=", main, newpwd);
	if (newpwd)
		free(newpwd);
	getcwd(cwd, 4096);
	ft_add_env("PWD=", main, cwd);
	ft_add_env_exp("PWD=", main, cwd);
}

int	ft_cd(t_main *main, char **cmd)
{
	int		status;

	status = 0;
	if (!cmd[1])
		return (ft_go_home(main));
	else if (cmd[2])
	{
		status = 1;
		ft_putendl_fd("-minishell: cd: too many arguments", STDERR);
	}
	else if (cmd[1][0] != '\0' && ft_strncmp(cmd[1], "-", 2) == 0)
		status = ft_go_back(main);
	else if (chdir(cmd[1]) == 0)
		ft_upd_pwd(main);
	else
		status = ft_cd_error(cmd);
	g_status = status;
	return (-1);
}
