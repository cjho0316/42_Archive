/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:18:24 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/12 14:51:46 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		i;

	n = nbr;
	i = nbr_len(n);
	if (!(str = (char *)malloc(i + 1)))
		return (0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n /= 10;
	}
	return (str);
}
