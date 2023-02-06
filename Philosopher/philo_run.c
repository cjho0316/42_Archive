/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:05:25 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/06 18:16:54 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_start(t_philo *phil, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		ft_mutex_last_eat(phil, info, 0, i);
		pthread_create(&(phil[i].thread), NULL, philo_thread, &(phil[i]));
	}
	philo_monitoring(phil, info);
	i = -1;
	while (++i < info->num_philo)
		pthread_join((phil[i].thread), NULL);
	return (0);
}

void	*philo_thread(void *av)
{
	t_philo	*phil;
	t_info	*info;

	phil = av;
	info = phil->info;
	if (phil->id % 2)
		usleep(500);
	while (ft_mutex_finish(info, 1) != 1)
	{
		philo_eating(phil, info);
		if (phil->eat_count == info->philo_must_eat)
		{
			ft_mutex_finished_eat(info, 0);
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
		ft_mutex_last_eat(phil, info, 1, 0);
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

	while (ft_mutex_finish(info, 1) != 1)
	{
		if ((info->philo_must_eat != 0) && \
		(info->num_philo == ft_mutex_finished_eat(info, 1)))
		{
			ft_mutex_finish(info, 0);
			break ;
		}
		i = -1;
		while (++i < info->num_philo)
		{
			curr = ft_gettime();
			if ((curr - ft_mutex_last_eat(phil, info, 2, i)) \
			>= info->time_to_die)
			{
				ft_mutex_print(info, i, "died");
				ft_mutex_finish(info, 0);
				break ;
			}
		}
	}
	return (0);
}

void	free_all_and_mutex_unlock(t_info *info, t_philo *phil)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&(info->print));
	pthread_mutex_destroy(&(info->finish));
	pthread_mutex_destroy(&(info->last_eat));
	pthread_mutex_destroy(&(info->finished_eating));
	while (++i < info->num_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
	}
	free(phil);
	free(info->forks);
}
