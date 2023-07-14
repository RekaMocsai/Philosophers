/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/14 18:30:04 by rmocsai          ###   ########.fr       */
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

typedef struct s_fork
{
	int	*fork;
	pthread_mutex_t	*fork_mutex_arr; 
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	struct t_fork	*left_fork;
	struct t_fork	*right_fork;
	struct timeval	last_eaten;
}	t_philo;

typedef struct s_big
{
	int				headcount;
	int				ttd;
	int				tte;
	int				tts;
	int				cycle;
	bool			all_alive;
	bool			all_full;
	int				*fork_arr;
	struct t_philo	*philoslist;
	struct t_fork	*forks;
	pthread_mutex_t	*fork_mutex_arr;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	eating_mutex;
	pthread_mutex_t	last_eaten_mutex;
	pthread_mutex_t	philos_mutex;
	struct timeval	start_time;
}	t_big;

/* Input checking */
int				input_checker(int argc, char **argv);
int				invalid_entry_check(t_big *big);

/* Utils */
int				ft_atoi(const char *str);

/* Initialize */
int				init_mainstruct(int ac, char **av, t_big *big);
int				create_threads(t_big *big);

#endif
