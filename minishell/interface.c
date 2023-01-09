/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:05:24 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/09 11:11:50 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exec builtin -> dup and pipe

//arg must be list type
int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "pwd") || !ft_strcmp(str, "echo")
		|| !ft_strcmp(str, "cd") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "export") || !ft_strcmp(str, "unset")
		|| !ft_strcmp(str, "exit"))
		return (1);
	else
		return (0);
}

//arg must be list type
void	builtin_interface(char *cmd)
{
	if (is_builtin)
	{
		if (!ft_strncmp(cmd, "pwd", 3))
			ft_env(cmd);
		else if (!ft_strncmp(cmd, "echo", 4))
			ft_echo(cmd);
		else if (!ft_strncmp(cmd, "cd", 2))
			ft_cd(cmd);
		else if (!ft_strncmp(cmd, "env", 3))
			ft_env(cmd);
		else if (!ft_strncmp(cmd, "export", 6))
			ft_export(cmd);
		else if (!ft_strncmp(cmd, "unset", 5))
			ft_unset(cmd);
		else if (!ft_strncmp(cmd, "exit", 4))
			ft_exit(cmd);
	}
	else
		printf("%s : command not found", cmd);
}
