/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:01:03 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 14:49:00 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	get_sig(int sig, siginfo_t *info, void *context)
{
	static char		asc;
	static int		tmp;
	static pid_t	c_pid;

	(void)context;
	if (!c_pid)
		c_pid = info->si_pid;
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
			kill(c_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		tmp = 0;
		asc = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = get_sig;
	av = 0;
	if (ac != 1)
	{
		ft_putstr_fd("Wrong Argument!", 1);
		exit(1);
	}
	ft_putstr_fd("Server pid is : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
