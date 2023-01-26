/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:05:35 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/26 18:35:20 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_time{
	time_t 		tv_sec;
	suseconds_t tv_usec;
}	t_time;

typedef struct s_philo
{
    // struct s_arg    *arg;
    pthread_t       thread;
    int             id;
    int             left;
    int             right;
    long long       last_eat_time;
    int             eat_count;
}		t_philo;

typedef struct s_info
{
    int             num_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             philo_must_eat;
    int             finish;
    int             finished_eat;
    long long       start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
}		t_info;

/* philo_util.c */
int	ft_atoi(const char *str);


#endif