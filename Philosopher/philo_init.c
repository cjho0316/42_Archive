/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:07:15 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/06 18:16:54 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* validity_check */
int	is_valid_arg(t_info *info, char **av)
{
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start_time = ft_gettime();
	info->fin = 0;
	if (info->num_philo <= 0 || info->time_to_die < 0 \
	||info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (-1);
	if (av[5] != NULL && ft_atoi(av[5]) > 0)
		info->philo_must_eat = ft_atoi(av[5]);
	return (0);
}

/* initializing */
int	philo_init(t_philo **phil, t_info *info)
{
	int	i;

	i = -1;
	*phil = malloc(sizeof(t_philo) * info->num_philo);
	if (phil == 0)
		return (-1);
	while (++i < info->num_philo)
	{
		(*phil)[i].info = info;
		(*phil)[i].id = i;
		(*phil)[i].left = i;
		(*phil)[i].eat_count = 0;
		(*phil)[i].right = (i + 1) % (info->num_philo);
		(*phil)[i].last_eat_time = ft_gettime();
	}
	return (0);
}

int	print_and_forks_mutex_init(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&(info->print), NULL);
	pthread_mutex_init(&(info->finish), NULL);
	pthread_mutex_init(&(info->last_eat), NULL);
	pthread_mutex_init(&(info->finished_eating), NULL);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (info->forks == 0)
		return (-1);
	while (++i < info->num_philo)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
	}
	return (0);
}

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
	while (ft_mutex_finish(info, 1) != 1)
	{
		curr = ft_gettime();
		if (curr - past >= wait_time)
			break ;
		usleep(20);
	}
}
