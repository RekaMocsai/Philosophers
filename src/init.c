/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/28 18:20:54 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	mutex_init_helper(t_big *big)
{
	if (pthread_mutex_init(&big->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&big->cycle_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&big->print_mutex), 1);
	if (pthread_mutex_init(&big->alive_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&big->print_mutex);
		pthread_mutex_destroy(&big->cycle_mutex);
		return (1);
	}
	return (0);
}

static int	init_mutexes(t_big *big)
{
	int	i;

	big->fork_mutex_arr = malloc (sizeof(pthread_mutex_t) * big->headcount);
	if (!big->fork_mutex_arr)
		return (write(2, "Fork_mutex_arr malloc error!\n", 29), 1);
	i = -1;
	while (++i < big->headcount)
	{
		if (pthread_mutex_init(&big->fork_mutex_arr[i], NULL) != 0)
		{
			print_errors("Mutex init failed!\n", 2);
			destroy_return_one(big->fork_mutex_arr, i);
			safe_free(big->fork_mutex_arr);
			return (1);
		}
	}
	if (mutex_init_helper(big))
	{
		print_errors("Mutex init failed!\n", 2);
		destroy_return_one(big->fork_mutex_arr, i); 
		free(big->fork_mutex_arr);
		return (1);
	}
	return (0);
}

static int	init_forkstruct(t_big *big)
{
	int	i;

	i = -1;
	big->forks = malloc (sizeof (t_fork) * big->headcount);
	if (!big->forks)
	{
		print_errors("Forks malloc error!\n", 2);
		return (1);
	}
	while (++i < big->headcount)
	{
		big->forks[i].in_use = &(big->fork_arr[i]);
		big->forks[i].fork_mutex = &(big->fork_mutex_arr[i]);
	}
	return (0);
}

int	init_main(t_big *big)
{
	if (init_forks(big))
		return (1);
	if (init_mutexes(big))
		return (free(big->fork_arr), 1);
	if (init_forkstruct(big))
	{
		safe_free(big->fork_arr);
		mutex_cleaner(big);
		return (1);
	}
	big->phil_arr = malloc (sizeof (t_philo) * big->headcount);
	if (!big->phil_arr)
	{
		free(big->fork_arr);
		mutex_cleaner(big);
		free(big->forks);
		print_errors("Phil_arr malloc error!\n", 2);
		return (1);
	}
	init_philos(big);
	return (0);
}
