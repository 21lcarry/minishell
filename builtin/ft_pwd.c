#include "../includes/minishell.h"

int	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, 4096))
	{
		ft_putendl_fd(cwd, 1);
		exit(0);
	}
	else
		exit(1);
}
