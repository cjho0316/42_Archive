/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:20:30 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/08 13:52:57 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int2char1(int nb, int *len)
{
	char	temp;

	temp = nb % 10 + '0';
	if (nb > 9)
		int2char1(nb / 10, len);
	write(1, &temp, 1);
	*len += 1;
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		*len += 1;
		int2char1(-nb, len);
	}
	else
		int2char1(nb, len);
}
