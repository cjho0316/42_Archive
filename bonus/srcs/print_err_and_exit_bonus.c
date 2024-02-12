/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_and_exit_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:53 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/04 19:56:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "define_bonus.h"

void	print_err_and_exit(t_err_type type)
{
	if (type == E_ARG_NUM)
		ft_putstr_fd("cub3d: put at least or only one argument: Error\n", \
				STDERR_FILENO);
	else if (type == E_ARG_EXTENSION)
		ft_putstr_fd("cub3d: invalid file type: Error\n", STDERR_FILENO);
	else if (type == E_MAP)
		ft_putstr_fd("cub3d: invalid map: Error\n", STDERR_FILENO);
	else
		perror("cub3d");
	exit(1);
}
