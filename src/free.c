/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:03:16 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/27 10:14:06 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

int	free_fork_mutexes(t_big *big)
{
	int	i;

	i = -1;
	while (++i < big->headcount)
	{
		if (pthread_mutex_destroy(big->fork_mutex_arr + i))
		{
			print_errors("System failure - can't destroy mutexes\n", 2);
			return (1);
		}
	}
	safe_free(big->fork_mutex_arr);
	return (0);
}

void	clean_all(t_big *big)
{
	destroy_return_one(big->fork_mutex_arr, big->headcount);
	pthread_mutex_destroy(&big->print_mutex);
	pthread_mutex_destroy(&big->cycle_mutex);
	pthread_mutex_destroy(&big->alive_mutex);
	safe_free(big->fork_arr);
	safe_free(big->fork_mutex_arr);
	safe_free(big->forks);
	safe_free(big->phil_arr);
}

void	mutex_cleaner(t_big *big)
{
	destroy_return_one(big->fork_mutex_arr, big->headcount);
	pthread_mutex_destroy(&big->print_mutex);
	pthread_mutex_destroy(&big->cycle_mutex);
	pthread_mutex_destroy(&big->alive_mutex);
	safe_free(big->fork_mutex_arr);
}
