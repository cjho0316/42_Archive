/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:46 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/26 19:07:57 by jang-cho         ###   ########.fr       */
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

/* validity check */

int is_valid_arg(t_info info, char **av)
{
	info.num_philo = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	if (info.num_philo <= 0 || info.time_to_die < 0 || info.time_to_eat < 0 || info.time_to_sleep < 0)
		return (-1);
	if (av[5] != NULL && ft_atoi(av[5]) > 0)
		info.philo_must_eat = ft_atoi(av[5]);
	return (0);
}

/* initializing */

int philo_init(t_philo **phil, t_info info)
{
	int i;

	i = -1;
	*phil = malloc(sizeof(t_philo) * info.num_philo);
	if (phil == 0)
		return (-2);
	while (++i < info.num_philo)
	{
		//(*phil)[i].arg = arg;
		(*phil)[i].id = i;
		(*phil)[i].eat_count = 0;
		(*phil)[i].left = i;
		(*phil)[i].right = (i + 1) % info.num_philo;
		(*phil)[i].last_eat_time = ft_gettime();
	}
	return (0);
}

int print_forks_mutex_init(t_info info)
{
	int i;

	i = -1;
	pthread_mutex_init(&(info.print), NULL);
	info.forks = malloc(sizeof(pthread_mutex_t) * info.num_philo);
	if (info.forks == 0)
		return (-2);
	while (++i < info.num_philo)
	{
		pthread_mutex_init(&(info.forks[i]), NULL);
	}
	return (0);
}

int philo_start(t_philo *phil, t_info info)
{
	int i;

	i = -1;
	while (++i < info.num_philo)
		pthread_create(&(phil[i].thread), NULL, philo_thread, &(phil[i]));
	philo_monitoring(phil, info);
	i = -1;
	while (++i < info.num_philo)
		pthread_join(&(phil[i].thread), NULL);
	return (0);
}

/* philo thread run */

int philo_thread(t_philo *phil, t_info info)
{
	pthread_mutex_lock(&(info.forks[phil->id]));
	ft_mutex_print(info, phil->id, "has taken a left fork");
	//
	pthread_mutex_lock(&(info.forks[(phil->id + 1) % info.num_philo]));
	ft_mutex_print(info, phil->id, "has taken a right fork");
	ft_mutex_print(info, phil->id, "is eating");
	phil->eat_count++;
	phil->last_eat_time = ft_gettime();
	ft_intermission(phil->last_eat_time);
	pthread_mutex_unlock(&(info.forks[(phil->id + 1) % info.num_philo]));
	//
	pthread_mutex_unlock(&(info.forks[phil->id]));
	return (0);
}

int philo_monitoring(t_philo *phil, t_info info)
{
	if (phil)
}

/* utils */

int ft_gettime(void)
{
	struct timeval 	tv1;
	long long		time;
	
	gettimeofday(&tv1, NULL);
	time = tv1.tv_sec % 10000 * 1000000 + tv1.tv_usec;
	return (time);
}

int ft_intermission(long long wait_time)
{
	long long		past;
	long long		pres;

	past = ft_gettime();
	while (pres-past > wait_time)
	if ()
		break;

	return (time);
}

int ft_mutex_print(t_info info, int id,char *str)
{
	long long cur;
	
	cur = ft_gettime();
	pthread_mutex_lock(&(info.print));
	if (info.finish != 1)
		printf("%lld, %d, %s\n",(cur-info.start_time), id + 1, str);
	pthread_mutex_unlock(&(info.print));
	return (0);
}

void ft_free_all()
{
}