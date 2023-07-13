/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/13 11:23:07 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX	2147483647
# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DIED		4

typedef struct s_fork
{
	int	id;
	pthread_mutex_t	fork_mutex; 
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				l_hand;
	int				r_hand;
	struct t_fork	*l_fork;
	struct t_fork	*r_fork;
	int				times_eaten;
	int				last_eaten;
}	t_philo;

typedef struct s_big
{
	int				headcount;
	int				ttd;
	int				tte;
	int				tts;
	int				cycle;
	int				all_alive;
	struct t_philo	*philoslist;
	struct t_fork	*forkslist;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	last_eaten_mutex;
	pthread_mutex_t	philos_mutex;
	struct timeval	start_time;
}	t_big;

/* Input checking */
int				input_checker(int argc, char **argv);
void			invalid_entry_check(t_big *big);

/* Utils */
int				ft_atoi(const char *str);

/* Initialize */
t_big			*init_mainstruct(int ac, char **av);

#endif
