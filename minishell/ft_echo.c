/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:38:09 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/10 15:59:36 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo $? implementation
#include "minishell.h"

void	ft_echo_plus(char **cmd)
{
	printf("print exit status (numeric arguments return)");
}

void	ft_echo(char **cmd)
{
	if (cmd[0][0] == '$' || cmd[0][0] == '?')
		ft_echo_plus(cmd);
	if (cmd[0][0] == '-')
	{
		if (cmd[0][1] == 'n')
			printf("%s", cmd[1]);
	}
	else
		printf("%s\n", cmd[1]);
}
