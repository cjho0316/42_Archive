/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:54:04 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/09 12:54:08 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int *len)
{
	int			bsize;
	long long	nb;

	bsize = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -(long long)nbr;
	}
	else
		nb = (long long)nbr;
	bsize = ft_strlen(base);
	if (nb > bsize - 1)
	{
		ft_putnbr_base(nb / bsize, base, len);
		ft_putnbr_base(nb % bsize, base, len);
	}
	else
	{
		write(1, &base[nb % bsize], 1);
		*len += 1;
	}
}
