/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:29:15 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/10 01:57:23 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			ti;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	ti = i - 1;
	while (nptr[++ti])
	{
		if (nptr[ti] < '0' || nptr[ti] > '9')
			return (-1);
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

long long	ft_gettime(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	ft_mutex_print(t_philo *philo, const char *str)
{
	long long	t;

	pthread_mutex_lock(&philo->info->print_mutex);
	if (!ft_mutex_check_finish(philo, 0))
	{
		t = ft_gettime() - philo->info->start_time;
		printf("%lld %d %s\n", t, philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	ft_intermission(t_philo *philo, long long ms)
{
	long long	t;

	t = ft_gettime();
	while (!ft_mutex_check_finish(philo, 0) && (ft_gettime() - t) < ms)
		usleep(100);
}
