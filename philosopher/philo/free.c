/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:28:16 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/12 11:38:03 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_info(t_info *info)
{
	free(info->philos);
	free(info->forks);
	return (0);
}

int	free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i]);
	free_info(info);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	return (0);
}

void	join_free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->philos[i].thread, NULL);
	free_destroy(info);
}

void	destroy(t_info *info)
{
	int	i;
	int	num;

	num = 1;
	while (num)
	{
		i = -1;
		info->finished_eat = 0;
		while (++i < info->num_philo)
		{
			if (num && philo_monitoring(&info->philos[i]))
				num = 0;
		}
		usleep(10);
	}
	join_free_destroy(info);
}
