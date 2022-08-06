/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:23 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/07 05:24:16 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_memory(unsigned long long nbr, char *base, int *len)
{
	unsigned long long	bsize;

	bsize = 0;

	bsize = ft_strlen(base);
	if (nbr > bsize - 1)
	{
		ft_print_memory(nbr / bsize, base, len);
		ft_print_memory(nbr % bsize, base, len);
	}
	else
	{
		write(1, &base[nbr % bsize], 1);
		*len += 1;
	}
}

void	ft_print_mem_address(unsigned long long nbr, int *len)
{
	ft_putstr("0x", len);
	ft_print_memory(nbr, "0123456789abcdef", len);
}
