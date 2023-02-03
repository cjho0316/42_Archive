/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:46 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/03 18:08:57 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	tv1;
	long long		time;

	gettimeofday(&tv1, NULL);
	time = tv1.tv_sec * 1000 + tv1.tv_usec / 1000;
	return (time);
}

void	ft_intermission(long long wait_time, t_info *info)
{
	long long		past;
	long long		curr;

	past = ft_gettime();
	while (!info->finish)
	{
		curr = ft_gettime();
		if (curr - past >= wait_time)
			break ;
		usleep(20);
	}
}

int	ft_mutex_print(t_info *info, int id, char *str)
{
	long long	time;

	time = ft_gettime() - info->start_time;
	pthread_mutex_lock(&(info->print));
	if (info->finish != 1)
		printf("%lld %d %s\n", (time), id + 1, str);
	pthread_mutex_unlock(&(info->print));
	return (0);
}

void	free_all_and_mutex_unlock(t_info *info, t_philo *phil)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&(info->print));
	while (++i < info->num_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
	}
	free(phil);
	free(info->forks);
}

int	main(int ac, char **av)
{
	int		err;
	t_info	info;
	t_philo	*phil;

	if (ac == 5 || ac == 6)
	{
		memset(&info, 0, sizeof(t_info));
		err = is_valid_arg(&info, av);
		if (err == -1)
			printf("no valid arguments!\n");
		philo_init(&phil, &info);
		print_and_forks_mutex_init(&info);
		philo_start(phil, &info);
		free_all_and_mutex_unlock(&info, phil);
	}
	else
		printf("mind your arguments!\n");
	return (0);
}
