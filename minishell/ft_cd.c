/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangchoi <jangchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:21:25 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/10 13:04:17 by jangchoi         ###   ########.fr       */
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
		printf("ERROR");
}

int	ft_cd_home(char **env, char *path)
{
	while (*env)
	{
		if (ft_strnstr(*env, "HOME", 4))
		{
			path = ft_strnstr(*env, "HOME", 4) + 5;
			if (chdir(path) == -1)
				printf("ERROR");
			return (1);
		}
		env++;
	}
	printf("ERROR");
	return (0);
}

int	ft_cd_env(char **env, char *path, char *absolute)
{
	int	len;

	len = ft_strlen(absolute);
	while (*env)
	{
		if (ft_strnstr(*env, absolute, len))
		{
			path = ft_strnstr(*env, absolute, len) + (len + 1);
			if (chdir(path) == -1)
				printf("ERROR");
			return (1);
		}
		env++;
	}
	printf("ERROR");
	return (0);
}

// argument as linked list type
void	ft_cd(char **cmd, char **env)
{
	// t_list	*p;
	char	*path;

	path = NULL;
	if (cmd[0] != NULL && cmd[0][1] != '~' && cmd[0][1] != '$')
	{
		ft_cd_any(env, path, cmd[1]);
	}
	else if (cmd[0][1] == '~' || cmd[0] == NULL)
	{
		ft_cd_home(env, path);
	}
	else if (cmd[0][1] == '$')
	{
		ft_cd_env(env, path, cmd[1]);
	}
}
