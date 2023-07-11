/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:05 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/11 15:02:31 by rmocsai          ###   ########.fr       */
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
	int				left;
	int				right;
	int				times_eaten;
}	t_philo;

typedef struct t_main
{
	int		nr;
    int     ttd;
    int     tte;
    int     tts;
    int     cycle;
    struct s_philo  *philos;
}   t_main;

/* Input checking */
int				input_checker(int argc, char **argv);

/* Utils */
int				ft_atoi(const char *str, int *ptr);


#endif
