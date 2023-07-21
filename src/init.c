/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/21 17:10:08 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_bigstruct(int ac, char **av, t_big *big)
{
	big->headcount = ft_atoi(av[1]);
	big->ttd = ft_atoi(av[2]);
	big->tte = ft_atoi(av[3]);
	big->tts = ft_atoi(av[4]);
	if (!big->headcount || !big->ttd || !big->tte || !big->tts)
	{
		printf("Invalid entry!\n");
		return (1);
	}
	if (ac == 6)
	{
		if (av[5] && av[5][0] == '0')
		{
			printf("Invalid entry\n");
			return (1);
		}	
		big->cycle = ft_atoi(av[5]);
	}
	else
		big->cycle = 0;
	if (invalid_entry_check(big))
		return (1);
	return (0);
}

int	destroy_return_one(pthread_mutex_t **forks)
{
	int	i;

	i = -1;
	while (forks[++i])
	{
		pthread_mutex_destroy(forks[i]);
	}
	return (1);
}

static int	destroy_check(pthread_mutex_t *ptr)
{
	if (ptr != NULL)
		pthread_mutex_destroy(ptr);
	return (1);
}	

static void	init_alive_mutex(t_big *big, int *i)
{
	if (pthread_mutex_init(&big->alive_mutex, NULL) != 0)
	{
		*i += destroy_check(&big->cycle_mutex);
		*i += destroy_check(&big->print_mutex);
		*i += destroy_check(&big->eating_mutex);
		*i += destroy_check(&big->all_stop_mutex);
	}
}

static int	mutex_init_helper(t_big *big)
{
	int	i;
	
	i = 0;
	if (pthread_mutex_init(&big->print_mutex, NULL) != 0)
		i++;
	if (pthread_mutex_init(&big->eating_mutex, NULL) != 0)
		i += destroy_check(&big->print_mutex);
 	if (pthread_mutex_init(&big->all_stop_mutex, NULL) != 0)
	{
		i += destroy_check(&big->print_mutex);
		i += destroy_check(&big->eating_mutex);
	}
	if (pthread_mutex_init(&big->cycle_mutex, NULL) != 0)
	{
		i += destroy_check(&big->print_mutex);
		i += destroy_check(&big->eating_mutex);
		i += destroy_check(&big->all_stop_mutex);
	}
	init_alive_mutex(big, &i);
	if (i)
		return (1);
	return (0);
}

static int	init_mutexes(t_big *big)
{
	int	i;
	
	big->fork_mutex_arr = malloc (sizeof(pthread_mutex_t) * big->headcount);
	if (!big->fork_mutex_arr)
		return (1);
	i = -1;
	while (++i < big->headcount)
	{
		if (pthread_mutex_init(big->fork_mutex_arr + i, NULL) != 0)
		{
			printf("Mutex init failed!\n");
			return (destroy_return_one(&big->fork_mutex_arr));
		}
	}
 	if (mutex_init_helper(big))
 	{
		printf("Mutex init failed!\n");
		return (1);
	}
	return (0);
}

static int	init_forks(t_big *big)
{
	int				i;

	big->fork_arr = malloc (sizeof (int) * big->headcount);
	if (!big->fork_arr)
		return (1);
	i = -1;
	while (++i < big->headcount)
		big->fork_arr[i] = 0;
	return (0);
}

static int	init_forkstruct(t_big *big)
{
	int	i;
	
	i = -1;
	while (++i < big->headcount)
	{
		big->forks[i].in_use = &(big->fork_arr[i]);
		big->forks[i].fork_mutex = &(big->fork_mutex_arr[i]);
	}
	return (0);
}

int	init_philos(t_big *big)
{
	int	i;

	i = -1;
	while (++i < big->headcount)
	{
		big->phil_arr[i].id = i;
		big->phil_arr[i].times_eaten = 0;
		big->phil_arr[i].big = big;
		big->phil_arr[i].l_fork = &(big->forks[i]);
		big->phil_arr[i].r_fork = &(big->forks[(i + 1) % big->headcount]);
	}
	return (0);
}

int	init_main(t_big *big)
{
	big->fork_mutex_arr = malloc (sizeof (pthread_mutex_t) * big->headcount);
	if (!big->fork_mutex_arr)
		return (1);
	big->forks = malloc (sizeof (t_fork) * big->headcount);
	if (!big->forks)
		return (1);
	if (init_forks(big) || init_mutexes(big) || init_forkstruct(big))
		return (1);
	big->phil_arr = malloc (sizeof (t_philo) * big->headcount);
	if (!big->phil_arr)
		return (1);
	if (init_philos(big))
	 	return (1);
	return (0);
}
