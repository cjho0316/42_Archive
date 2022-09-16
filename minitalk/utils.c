/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:35:06 by jang-cho          #+#    #+#             */
/*   Updated: 2022/09/17 03:59:05 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	k;
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		k = str[idx];
		write (1, &k, 1);
		idx++;
	}
}

int	put_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'\
		|| str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		i++;
		i *= -1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	result;

	i = put_idx(str);
	n = 1;
	result = 0;
	if (!str)
		return (0);
	if (i < 0)
	{
		n = -1;
		i *= -1;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if ((result * n) >= 9223372036854775807)
		return (-1);
	else if ((result * n * -1) - 1 > 9223372036854775807)
		return (0);
	else
		return (result * n);
}

void	int2char(int nb)
{
	char	temp;

	temp = nb % 10 + '0';
	if (nb > 9)
		int2char(nb / 10);
	write(1, &temp, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		int2char(-nb);
	}
	else
		int2char(nb);
}