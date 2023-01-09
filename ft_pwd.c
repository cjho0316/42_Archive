/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangchoi <jangchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:21:20 by jangchoi          #+#    #+#             */
/*   Updated: 2023/01/08 13:43:18 by jangchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(char *str)
{
    char cwd[1024];

    (void)str;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
      printf("getcwd() error");
    else
      printf("%s\n", cwd);
}
