#include "minishell.h"

int	built_in_main(t_lexical *lexical, t_command *command)
{
	char	*cmd;

	cmd = command->command;
	if (ft_strncmp(cmd, "export", 6) == 0
		&& lexical->next && lexical->next->type == WORD)
		return (!export_cmd(command));
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (!unset_cmd(command));
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (!cd_fn(command));
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		exit(free_all());
	return (0);
}

int	built_in_fork(t_command *command)
{
	char	*cmd;
	char	*res;

	cmd = command->command;
	if (ft_strncmp(cmd, "echo", 3) == 0)
		return (!echo_cmd(command));
	else if (ft_strncmp(cmd, "env", 3) == 0)
		return (!print_env());
	if (ft_strncmp(cmd, "export", 6) == 0)
		return (!export_cmd(command));
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
	{
		get_pwd(&res);
		ft_putstr_fd(res, 1);
		ft_putstr_fd("\n", 1);
		del_malloc(res);
		return (1);
	}
	return (0);
}
