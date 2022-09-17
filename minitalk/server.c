/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:01:03 by jang-cho          #+#    #+#             */
/*   Updated: 2022/09/17 04:03:40 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int tmp = 0;
void get_sig(int sig)
{
	static char asc;
	// tmp = 0;
	if (sig == SIGUSR1){
		asc |= 0;
	}
	else if (sig == SIGUSR2){
		asc |= 1;
	}
	tmp += 1;
	
	if (tmp < 8){
		asc <<= 1;
	}
	
	if (tmp == 8)
	{
		write(1, &asc, 1);
		tmp = 0;
		asc = 0;
	}
}

//msg recieved from client.. handle and print
int main (int ac, char **av)
{
	av = 0;
	if (ac != 1)
	{
		ft_putstr("Wrong Argument!");
		exit(1);
	}
	ft_putstr("Server pid is : ");
	ft_putnbr(getpid());
	signal(SIGUSR1, get_sig);	//signal function
	signal(SIGUSR2, get_sig);
	while(1)					// pause til signal come
		pause();
}
