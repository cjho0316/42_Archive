/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:56 by jang-cho          #+#    #+#             */
/*   Updated: 2022/09/17 04:04:29 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void atob(int pid, char *str)
{
	int bit_cnt;
	int byt_idx;
	int tmp;

	byt_idx = 0;
	while (str[byt_idx] != '\n')
	{
		bit_cnt = 0;
		while (bit_cnt < 8)
		{
			tmp = (str[byt_idx] >> (7 - bit_cnt));
			tmp &= 1;
			if (tmp == 0)
				kill (pid, SIGUSR1);
			else if (tmp == 1)
				kill (pid, SIGUSR2);
			usleep(10);
			bit_cnt += 1;
		}
		usleep(100);
		byt_idx += 1;
	}
}
// parsing ascii word -> string
// signal catch(kill) -> sigusr1 = 0 sigusr2 = 1

void send_sig(int pid, char *av)
{
	char *str;
	
	str = ft_strjoin(av, "\n");
	if (str == NULL)
		exit(1);
	atob(pid, str);
	free(str);
	exit(0);
}

int main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Wrong args!");
		return (0);
	}
	pid = ft_atoi(av[1]);		// int pid
	if (pid <= 100)
		exit(1);
	send_sig(pid, av[2]);		// ascii word

	return (0);
}
