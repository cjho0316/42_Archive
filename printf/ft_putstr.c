/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:39:22 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/07 04:51:13 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	k;
	int	idx;

	idx = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (str[idx] != '\0')
		{
			k = str[idx];
			write (1, &k, 1);
			*len += 1;
			idx++;
		}
	}
}
