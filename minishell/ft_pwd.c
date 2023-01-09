/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:05:34 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/09 11:33:14 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char *str)
{
	char	cwd[1024];

	(void)str;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		printf("getcwd() error");
	else
		printf("%s\n", cwd);
}
