/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:21:25 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/10 15:55:20 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 에러헨들링 메시지 추가 구현 시켜주기
// oldpwd, pwd 에 대한 선언

#include "minishell.h"

void	ft_cd_any(char **env, char *path, char *anywhere)
{
	(void)env;
	path = anywhere;
	if (chdir(path) == -1)
		printf("ERROR_any\n");
}

int	ft_cd_home(char **env, char *path)
{
	while (*env)
	{
		if (ft_strnstr(*env, "HOME=", 5))
		{
			path = ft_strnstr(*env, "HOME=", 5) + 5;
			printf("home path is: %s\n", path); // dbg
			if (chdir(path) == -1)
				printf("ERROR_home\n");
			return (1);
		}
		env++;
	}
	printf("ERROR_home\n");
	return (0);
}

int	ft_cd_env(char **env, char *path, char *absolute)
{
	int		len;
	char	*absol_plus;

	absol_plus = ft_strjoin(absolute, "=");
	len = ft_strlen(absol_plus);
	while (*env)
	{
		if (ft_strnstr(*env, absol_plus, len))
		{
			path = ft_strnstr(*env, absol_plus, len) + (len);
			printf("env path is: %s\n", path); // dbg
			if (chdir(path) == -1)
				printf("ERROR_env\n");
			return (1);
		}
		env++;
	}
	printf("ERROR_env\n");
	return (0);
}

// argument as linked list type
void	ft_cd(char **cmd, char **env)
{
	// t_list	*p;
	char	*path;

	path = NULL;
	if (cmd[0][0] != '\0' && cmd[0][0] != '~' && cmd[0][0] != '$')
	{
		ft_cd_any(env, path, cmd[0]);
	}
	else if (cmd[0][0] == '~' || cmd[0][0] == '\0')
	{
		ft_cd_home(env, path);
	}
	else if (cmd[0][0] == '$')
	{
		ft_cd_env(env, path, cmd[1]);
	}
}
