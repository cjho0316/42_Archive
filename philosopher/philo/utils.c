/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:29:15 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/12 11:48:56 by jang-cho         ###   ########.fr       */
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

int	ft_atoi(const char *ptr)
{
	int			i;
	int			t;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	if (ptr[i] == '-')
		sign *= -1;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	t = i - 1;
	while (ptr[++t])
	{
		if (ptr[t] < '0' || ptr[t] > '9')
			return (-1);
	}
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
	{
		n = n * 10 + (ptr[i] - '0');
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
