/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    philo_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:05:25 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/03 18:09:09 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_start(t_philo *phil, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		phil[i].last_eat_time = ft_gettime();
		pthread_create(&(phil[i].thread), NULL, philo_thread, &(phil[i]));
	}
	philo_monitoring(phil, info);
	i = -1;
	while (++i < info->num_philo)
		pthread_join((phil[i].thread), NULL);
	return (0);
}

/* philo thread run */
void	*philo_thread(void *av)
{
	t_philo	*phil;
	t_info	*info;

	phil = av;
	info = phil->info;
	if (phil->id % 2)
		usleep(500);
	while (info->finish != 1)
	{
		philo_eating(phil, info);
		if (phil->eat_count == info->philo_must_eat)
		{
			info->finished_eat += 1;
			break ;
		}
		ft_mutex_print(info, phil->id, "is sleeping");
		ft_intermission(info->time_to_sleep, info);
		ft_mutex_print(info, phil->id, "is thinking");
	}
	return (av);
}

int	philo_eating(t_philo *phil, t_info *info)
{
	pthread_mutex_lock(&(info->forks[phil->left]));
	ft_mutex_print(info, phil->id, "has taken a fork");
	if (info->num_philo != 1)
	{
		pthread_mutex_lock(&(info->forks[phil->right]));
		ft_mutex_print(info, phil->id, "has taken a fork");
		ft_mutex_print(info, phil->id, "is eating");
		phil->last_eat_time = ft_gettime();
		phil->eat_count++;
		ft_intermission((long long)info->time_to_eat, info);
		pthread_mutex_unlock(&(info->forks[phil->right]));
	}
	pthread_mutex_unlock(&(info->forks[phil->left]));
	return (0);
}

int	philo_monitoring(t_philo *phil, t_info *info)
{
	long long	curr;
	int			i;

	while (!info->finish)
	{
		if ((info->philo_must_eat != 0) && \
		(info->num_philo == info->finished_eat))
		{
			info->finish = 1;
			break ;
		}
		i = -1;
		while (++i < info->num_philo)
		{
			curr = ft_gettime();
			if ((curr - phil[i].last_eat_time) >= info->time_to_die)
			{
				ft_mutex_print(info, i, "died");
				info->finish = 1;
				break ;
			}
		}
	}
	return (0);
}
