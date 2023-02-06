/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:46 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/06 18:16:53 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_mutex_last_eat(t_philo *phil, t_info *info, int check, int id)
{
	long long	val;

	val = 0;
	pthread_mutex_lock(&(info->last_eat));
	if (check == 0)
	{
		phil[id].last_eat_time = ft_gettime();
	}
	if (check == 1)
	{
		(void)id;
		phil->last_eat_time = ft_gettime();
	}
	else if (check == 2)
	{
		val = phil[id].last_eat_time;
	}
	pthread_mutex_unlock(&(info->last_eat));
	return (val);
}

int	ft_mutex_print(t_info *info, int id, char *str)
{
	long long	time;

	time = ft_gettime() - info->start_time;
	pthread_mutex_lock(&(info->print));
	if (ft_mutex_finish(info, 1) != 1)
		printf("%lld %d %s\n", (time), id + 1, str);
	pthread_mutex_unlock(&(info->print));
	return (0);
}

int	ft_mutex_finished_eat(t_info *info, int check)
{
	int	val;

	val = 0;
	pthread_mutex_lock(&(info->finished_eating));
	if (check == 1)
	{
		val = info->finished_eat;
	}
	else if (check == 0)
	{
		info->finished_eat++;
	}
	pthread_mutex_unlock(&(info->finished_eating));
	return (val);
}

int	ft_mutex_finish(t_info *info, int check)
{
	int	val;

	val = 0;
	pthread_mutex_lock(&(info->finish));
	if (check == 1)
	{
		val = info->fin;
	}
	else if (check == 0)
	{
		info->fin = 1;
	}
	pthread_mutex_unlock(&(info->finish));
	return (val);
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
