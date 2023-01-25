/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:05:35 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/25 18:40:14 by jang-cho         ###   ########.fr       */
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

typedef struct s_info{
	int num_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_philo_must_eat;
} 	t_info;

typedef struct  s_philosopher
{
    t_info     		rule_info;
    int             id;
    int             eat_count;
    long long       public_time;
    long long       eating_start_time;
    long long       last_eat_time;
    // pthread_t       thread;
    pthread_t print;
    pthread_t left_fork;
    pthread_t right_fork;
}	t_philo;

// typedef struct  s_philosophers_info
// {
//     t_philosopher 	*philosopher;
//     pthread_t 		*threads;
//     pthread_mutex_t *forks;
//     pthread_mutex_t mutex_print;
// }	t_philosophers_info;

/* philo_util.c */
int	ft_atoi(const char *str);


#endif