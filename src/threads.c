/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:15:23 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/25 17:43:45 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//get_starttime here?
int	create_threads(t_philo *phil_arr)
{
	int	i;

	phil_arr->big->start_time = get_starttime();
	i = -1;
	while (++i < phil_arr->big->headcount)
	{
		phil_arr[i].last_eaten = phil_arr->big->start_time;
		if (pthread_create(&phil_arr[i].tid, NULL, workwork, &phil_arr[i]))
		{
			//join_successful creates?
			return (1);
		}
	}
	whatsup(phil_arr, phil_arr->big);
	if (thread_joiner(phil_arr))
		return (1);
	return (0);
}

/* Monitors statuses while other threads are doing their thing */
void	whatsup(t_philo *phil_arr, t_big *big)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < big->headcount && philos_all_alive(big))
		{
			pthread_mutex_lock(&big->alive_mutex);
			if ((get_starttime() - phil_arr[i].last_eaten) >= big->ttd)
			{
				pthread_mutex_unlock(&big->alive_mutex);
				print_msgs(&phil_arr[i], DIED);
				big->all_alive = false;
				pthread_mutex_lock(&big->alive_mutex);
			}
			pthread_mutex_unlock(&big->alive_mutex);
		}
		if (!philos_all_alive(big) || philos_all_eaten(big))
			break ;
	}
}

/* waits till all threads finished, destroys all mutexes */
int	thread_joiner(t_philo *philo_arr)
{
	int		i;
	t_big	*big;

	big = philo_arr->big;
	i = -1;
	while (++i < big->headcount)
	{
		if (pthread_join(philo_arr[i].tid, NULL) != 0)
			return (1);
	}
	i = 0;
	while (i < big->headcount)
		pthread_mutex_destroy(&big->fork_mutex_arr[i++]);
	pthread_mutex_destroy(&big->print_mutex);
	pthread_mutex_destroy(&big->alive_mutex);
	pthread_mutex_destroy(&big->cycle_mutex);
	free_all_safely(big);
	return (0);
}
