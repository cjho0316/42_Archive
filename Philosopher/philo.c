/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:46 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/25 18:44:40 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int 	err;
	t_info	info;
	t_philo	*phil;

	if (ac == 5 || ac == 6)
	{
		memset(&info, 0, sizeof(t_info));
		err = is_valid_arg(info, av);
		if (err == -1)
			printf("no valid arguments!\n");
		err = philo_init(&phil, info);
		if (err == -2)
			printf("philo initializing error!\n");
		err = thread_init(av);
		if (err == -3)
			printf("philo running error!\n");
	}
	else
		printf("mind your arguments!\n");
	return (0);
}

int is_valid_arg(t_info info, char **av)
{
	info.num_philo = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	if (info.num_philo <= 0 || info.time_to_die < 0 || info.time_to_eat < 0 || info.time_to_sleep < 0)
		return (-1);
	if (av[5] != NULL && ft_atoi(av[5]) > 0)
		info.num_of_philo_must_eat = ft_atoi(av[5]);
	return (0);
}

int philo_init(t_philo **phil, t_info info)
{
	int i;

	i = -1;
	*phil = malloc(sizeof(t_philo) * info.num_philo);
	while (++i < info.num_philo)
	{
		(*phil)[i].id = i;
		(*phil)[i].eat_count = 0;
		(*phil)[i].left_fork = i;
		(*phil)[i].right_fork = (i + 1) % info.num_philo;
		(*phil)[i].last_eat_time = 0;
	}
	mutex_init();
}

int mutex_init(t_philo **philo)
{
	pthread_mutex_init(, NULL, )

}