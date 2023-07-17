/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/17 15:45:08 by rmocsai          ###   ########.fr       */
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

//forks arr
typedef struct s_fork
{
	int	*fork;
	pthread_mutex_t	fork_mutex; 
}	t_fork;

//philosophers_arr
typedef struct s_philo
{
	int				id;
	int				times_eaten;
	struct t_fork	*l_fork;
	struct t_fork	*r_fork;
	struct timeval	last_eaten;
	struct t_big	*big;
}	t_philo;

//main struct
typedef struct s_big
{
	int				headcount;
	int				ttd;
	int				tte;
	int				tts;
	int				cycle;
	bool			all_alive;
	bool			all_full;
	pthread_mutex_t	*fork_mutex_arr;
	int				*fork_arr;
	struct t_philo	*phil_arr;
	struct t_fork	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	all_stop_mutex;
	pthread_mutex_t	eating_mutex;
	struct timeval	start_time;
}	t_big;

/* Input checking */
int				input_checker(int argc, char **argv);
int				invalid_entry_check(t_big *big);

/* Utils */
int				ft_atoi(const char *str);

/* Initialize */
int				init_bigstruct(int ac, char **av, t_big *big);
int				create_threads(t_big *big);
int				init_main(t_big *big);
int				init_philos(t_big *big);

/* free */
int				free_fork_mutexes(t_big *big);
void			safe_free(void *ptr);
#endif
