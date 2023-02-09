/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:28:24 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/10 01:54:44 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	if ((ft_gettime() - philo->last_eat_time) >= philo->info->time_to_die)
	{
		ft_mutex_print(philo, "died");
		ft_mutex_check_finish(philo, 1);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return (1);
	}
	else if (philo->info->num_must_eat > 0 && philo->eat_cnt >= \
			philo->info->num_must_eat)
	{
		philo->info->finished_eat++;
		if (philo->info->finished_eat >= philo->info->num_philo)
		{
			ft_mutex_check_finish(philo, 1);
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (0);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	ft_mutex_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	ft_mutex_print(philo, "has taken a fork");
	ft_mutex_print(philo, "is eating");
	ft_intermission(philo, philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->eat_cnt += 1;
	philo->last_eat_time = ft_gettime();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}

int	ft_mutex_check_finish(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (num == 1)
	{
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->finish_mutex);
	return (0);
}

void	*philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 500);
	while (1)
	{
		if (ft_mutex_check_finish(philo, 0))
			return (0);
		philo_eating(philo);
		ft_mutex_print(philo, "is sleeping");
		ft_intermission(philo, philo->info->time_to_sleep);
		ft_mutex_print(philo, "is thinking");
	}
	return (0);
}
