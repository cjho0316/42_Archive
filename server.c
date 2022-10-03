/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:01:03 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/02 15:50:14 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_sig(int sig)
{
	static char	asc;
	static int	tmp;

	if (sig == SIGUSR1)
		asc |= 0;
	else if (sig == SIGUSR2)
		asc |= 1;
	tmp += 1;
	if (tmp < 8)
		asc <<= 1;
	if (tmp == 8)
	{
		write(1, &asc, 1);
		if (asc == 0)
		{
			write(1, "\n", 1);
		}
		tmp = 0;
		asc = 0;
	}
}

int	main(int ac, char **av)
{
	av = 0;
	if (ac != 1)
	{
		ft_putstr_fd("Wrong Argument!", 1);
		exit(1);
	}
	ft_putstr_fd("Server pid is : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		pause();
}
