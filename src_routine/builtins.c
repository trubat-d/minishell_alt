#include "minishell.h"

int	get_pwd(char **buff)
{
	if (ft_malloc((void **)buff, 255)
		|| !getcwd(*buff, 255))
		return (1);
	return (0);
}
//TODO : ADD FEATURE FOR +>  "-" OLDPWD
int	cd_fn(t_command *command)
{
	char	*path;

	path = command->arguments[1];
	if (!path)
	{
		if (get_env(&path, "HOME"))
			return (1);
	}
	printf("value of path = >> %s\n", path);
	if (chdir((const char *)path) < 0)
		return (1);
	return (0);
}

int	echo_cmd(t_command *command)
{
	int		option;

	option = 0;
	command->arguments++;
	if (!*command->arguments)
		return (1);
	if (ft_strncmp(*command->arguments, "-n", 2) == 0)
	{
		command->arguments++;
		option++;
	}
	while (*command->arguments)
		ft_putstr_fd(*(command->arguments++), 1);
	if (!option)
		ft_putstr_fd("\n", 1);
	return (0);
}

//TODO: correct unset command
int	unset_cmd(t_command *command)
{
	char	**env;

	env = command->arguments;
	env++;
	while (*env)
		del_env(*(env++));
	return (0);
}
