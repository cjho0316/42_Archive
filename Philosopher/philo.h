/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PHILO.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:13:33 by jang-cho          #+#    #+#             */
/*   Updated: 2023/02/03 17:14:04 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}		t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	int				finished_eat;
	long long		start_time;
	int				fin;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	finished_eating;
	pthread_mutex_t	finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}		t_info;

/* philo util */
int				ft_atoi(const char *str);

/* philo */

long long		ft_mutex_last_eat(t_philo *phil, t_info *info, \
int check, int id);
void			ft_intermission(long long wait_time, t_info *info);
int				ft_mutex_print(t_info *info, int id, char *str);
int				ft_mutex_finished_eat(t_info *info, int check);
int				ft_mutex_finish(t_info *info, int check);

/* philo init */
int				is_valid_arg(t_info *info, char **av);
int				philo_init(t_philo **phil, t_info *info);
int				print_and_forks_mutex_init(t_info *info);
long long		ft_gettime(void);
void			ft_intermission(long long wait_time, t_info *info);

/* philo run */
int				philo_start(t_philo *phil, t_info *info);
void			*philo_thread(void *av);
int				philo_eating(t_philo *phil, t_info *info);
int				philo_monitoring(t_philo *phil, t_info *info);
void			free_all_and_mutex_unlock(t_info *info, t_philo *phil);

#endif