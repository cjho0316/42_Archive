/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:56 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/02 16:20:16 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	received_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("msg received successfully", 1);
}

void	atob(int pid, char *str, int len)
{
	int	bit_cnt;
	int	byt_idx;
	int	tmp;

	byt_idx = 0;
	while (byt_idx <= len)
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
			usleep(20);
			bit_cnt += 1;
		}
		usleep(200);
		byt_idx += 1;
	}
}

void	send_sig(int pid, char *av)
{
	char	*str;
	int		len;

	str = ft_strjoin(av, "");
	len = ft_strlen(str);
	if (str == NULL)
		exit(1);
	atob(pid, str, len);
	free(str);
	exit(0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Wrong args!", 1);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 100)
		exit(1);
	send_sig(pid, av[2]);
	SIGNAL(SIGUSR1, received_ack);
	SIGNAL(SIGUSR2, received_ack);
	while (1)
		pause();
}
