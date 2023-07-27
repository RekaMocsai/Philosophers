/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:15:23 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/27 10:16:56 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	emergency_stop(t_big *big)
{
	while (1)
	{
		pthread_mutex_lock(&big->alive_mutex);
		big->all_alive = false;
		pthread_mutex_unlock(&big->alive_mutex);
		if (!philos_all_alive(big))
			break ;
	}
}

//get_starttime here?
int	create_threads(t_philo *phil_arr)
{
	int	i;

	i = -1;
	while (++i < phil_arr->big->headcount)
	{
		phil_arr[i].start_time = get_starttime();
		phil_arr[i].last_eaten = get_starttime();
		if (pthread_create(&phil_arr[i].tid, NULL, workwork, &phil_arr[i]))
		{
			print_errors("Thread creation failed!\n", 2);
			emergency_stop(phil_arr->big);
			return (join_successful_threads(i, phil_arr),
				clean_all(phil_arr->big), 1);
		}
	}
	whatsup(phil_arr, phil_arr->big);
	thread_joiner(phil_arr);
	return (0);
}

/* Monitors statuses while other threads are doing their thing
 - checks if ttd reached for each philo thread, sets all_alive if yes
 - also checks statuses each loop -> all alive or all eaten ->stop */
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
				pthread_mutex_lock(&big->alive_mutex);
				big->all_alive = false;
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
		{
			print_errors("System failure - unsuccesful at joining threads\n", 2);
			break ;
		}
	}
	clean_all(philo_arr->big);
	return (0);
}

int	print_msgs(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->big->print_mutex);
	if (philos_all_alive(philo->big) && !philos_all_eaten(philo->big))
	{
		if (i == TAKEN_FORK)
			printf("%ld %d has taken a fork\n", \
			get_starttime() - philo->start_time, philo->id + 1);
		else if (i == EATING)
			printf("%ld %d is eating\n", \
			get_starttime() - philo->start_time, philo->id + 1);
		else if (i == SLEEPING)
			printf("%ld %d is sleeping\n", \
			get_starttime() - philo->start_time, philo->id + 1);
		else if (i == THINKING)
			printf("%ld %d is thinking\n", \
			get_starttime() - philo->start_time, philo->id + 1);
		else if (i == DIED)
			printf("%ld %d died\n", \
			get_starttime() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(&philo->big->print_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->big->print_mutex);
	return (1);
}
