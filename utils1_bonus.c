/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:23:18 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 14:49:18 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	int2char(int n, int fd)
{
	char	temp;

	temp = n % 10 + '0';
	if (n > 9)
		int2char(n / 10, fd);
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		int2char(-n, fd);
	}
	else
		int2char(n, fd);
}
