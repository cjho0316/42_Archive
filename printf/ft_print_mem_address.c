/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:52:08 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/09 13:09:11 by jang-cho         ###   ########.fr       */
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
