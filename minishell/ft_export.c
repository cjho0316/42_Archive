/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:15:28 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/09 18:08:51 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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