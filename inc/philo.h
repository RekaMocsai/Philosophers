/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/12 14:23:56 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647
typedef struct s_philo
{
	int				id;
	int				l_hand;
	int				r_hand;
	int				times_eaten;
}	t_philo;

typedef struct s_fork
{
	int	id;
	pthread_mutex_t	fork_mutex; 
}	t_fork;


typedef struct s_big
{
	int		philo_nr;
	int		ttd;
	int		tte;
	int		tts;
	int		cycle;
	int		all_alive;
	struct s_philo  *philos;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	last_eaten_mutex;
	pthread_mutex_t	philos_mutex;
}	t_big;

/* Input checking */
int				input_checker(int argc, char **argv);
void			invalid_entry_check(t_big *big);

/* Utils */
int				ft_atoi(const char *str);

/* Initialize */
t_big			*init_mainstruct(int ac, char **av);

#endif
