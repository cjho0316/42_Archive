/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangchoi <jangchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:00:13 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/08 13:09:46 by jangchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//데이터 어케관리할지 고민
void	ft_env(char **env)
{
	while (*env)
		printf("%s\n", *env++);
}

void	ft_export(char *str, ...)
{
	int		i;
	char	*key;
	char	*val;
	char	**tmp;

	i = -1;
	key = NULL;
	val = NULL;
	tmp = ft_split(str, ' ');
	while (tmp[++i])
	{
		key = tmp[i];
		if (tmp[i][0] == '=' || ft_isdigit(tmp[i][0]))
		{
			printf("%s: not a valid identifier\n", tmp[i]);
			exit(1);
		}
		while (*str)
		{
			if (*str == '=')
				break ;
			str++;
		}
		str ++;
		val = str;
		// printf("%s\n", key);
		// printf("%s\n", val);
	}
}

void	get_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			printf("bash: unset: '%s': not a valid identifier", str);
			exit(1);
		}
		i++;
	}
}
