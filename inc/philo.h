/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/25 12:51:43 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define INT_MAX	2147483647
# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DIED		4

typedef struct s_big	t_big;
typedef struct s_philo	t_philo;

//forks arr		in use: 0=no 1=yes
typedef struct s_fork
{
	int				*in_use;
	pthread_mutex_t	*fork_mutex;
}	t_fork;

//philosophers_arr
typedef struct s_philo
{
	int				id;
	int				times_eaten;
	t_fork			*l_fork;
	t_fork			*r_fork;
	unsigned long	last_eaten;
	t_big			*big;
	pthread_t		tid;
}	t_philo;

//main struct
typedef struct s_big
{
	int				headcount;
	unsigned long	ttd;
	unsigned long	tte;
	unsigned long	tts;
	int				cycle;
	unsigned long	start_time;
	bool			all_alive;
	bool			all_full;
	int				*fork_arr;
	pthread_mutex_t	*fork_mutex_arr;
	t_philo			*phil_arr;
	t_fork			*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	cycle_mutex;
	pthread_mutex_t	eating_mutex;
	pthread_mutex_t	all_stop_mutex;
}	t_big;

/* Input checking */
int				input_checker(int argc, char **argv);
int				invalid_entry_check(t_big *big);

/* Utils */
unsigned long	ft_atoi(const char *str);
int				print_msgs(t_philo *philo, int i);
void			stop_all(t_big *big);

/* Initialize */
int				init_bigstruct(int ac, char **av, t_big *big);
int				create_threads(t_philo *phil_arr);
int				init_main(t_big *big);
int				init_forks(t_big *big);
int				init_philos(t_big *big);
int				destroy_check(pthread_mutex_t *ptr);
int				destroy_return_one(pthread_mutex_t **forks);

/* Time */
unsigned long	get_starttime(void);
void			custom_usleep(unsigned long time);

/* Threading */
int				create_threads(t_philo *phil_arr);
int				philos_all_eaten(t_big *big);
int				philos_all_alive(t_big *big);
void			*workwork(void *arg);
void			whatsup(t_philo *phil_arr, t_big *big);
int				thread_joiner(t_philo *philo_arr);

/* Routine */
void			be_eating(t_philo *philo);

/* free */
int				free_fork_mutexes(t_big *big);
void			safe_free(void *ptr);
#endif
