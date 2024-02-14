/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:28:36 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/12 11:38:05 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		info->num_philo = ft_atoi(av[1]);
		info->time_to_die = ft_atoi(av[2]);
		info->time_to_eat = ft_atoi(av[3]);
		info->time_to_sleep = ft_atoi(av[4]);
		info->start_time = ft_gettime();
		if (info->num_philo < 1 || info->time_to_die < 1 || \
				info->time_to_eat < 1 || info->time_to_sleep < 1)
			return (print_error("Error: wrong input\n"));
		if (ac == 6)
		{
			info->num_must_eat = ft_atoi(av[5]);
			if (info->num_must_eat < 1)
				return (print_error("Error: wrong input\n"));
		}
		else
			info->num_must_eat = -1;
		info->finish = 0;
	}
	return (0);
}

int	init_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->philos || !info->forks)
		return (1);
	while (++i < info->num_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num_philo;
		info->philos[i].eat_cnt = 0;
		info->philos[i].last_eat_time = ft_gettime();
		info->philos[i].info = info;
	}
	return (0);
}

int	init_mutexes(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->eat_mutex, NULL);
	pthread_mutex_init(&info->finish_mutex, NULL);
	while (++i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
	}
	return (0);
}

int	create_philos(t_info *info)
{
	int	i;

	i = -1;
	if (info->num_philo == 1)
	{
		ft_mutex_print(&info->philos[0], "has taken a fork");
		ft_intermission(&info->philos[0], info->time_to_die);
		ft_mutex_print(&info->philos[0], "died");
		ft_mutex_check_finish(&info->philos[0], 1);
		return (0);
	}
	while (++i < info->num_philo)
	{
		pthread_create(&info->philos[i].thread, NULL, philo_start, \
			&(info->philos[i]));
	}
	return (0);
}
