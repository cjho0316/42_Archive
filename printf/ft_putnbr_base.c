/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:23 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/07 02:44:26 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_nullandlabel(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == ' ' || str[i] == '\t'\
			|| str[i] == '\n' || str[i] == '\v'\
			|| str[i] == '\f' || str[i] == '\r')
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int			bsize;
	long long	nb;

	bsize = 0;
	if (check_nullandlabel(base) && check_double(base))
	{
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
}
