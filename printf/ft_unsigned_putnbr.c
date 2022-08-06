/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 05:20:30 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/07 03:02:47 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int2char(int nb, int *len)
{
	char	temp;

	temp = nb % 10 + '0';
	if (nb > 9)
		int2char(nb / 10, len);
	write(1, &temp, 1);
	*len += 1;
}

void	ft_unsigned_putnbr(unsigned int nb, int *len)
{
	int2char(nb, len);
}
