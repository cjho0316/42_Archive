/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:12:36 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/11 23:21:25 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
