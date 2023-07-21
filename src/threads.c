/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:15:23 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/21 17:21:30 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	create_threads(t_philo *phil_arr)
{
	//get_starttime here?
	int	i;

	i = -1;
	while (++i < phil_arr->big->headcount)
	{
		phil_arr[i].last_eaten = phil_arr->big->start_time;
		if (pthread_create(&phil_arr[i].tid, NULL,	workwork, &phil_arr[i]))
			return (1);
	}
	whatsup(phil_arr, phil_arr->big);
	//pthread_mutex_unlock(&phil_arr->big.print_mutex); was never locked?
	//thread_kill(phil_arr, phil_arr->big);
	return (0);
}

void	*workwork(void *arg)
{
	t_philo		*philo;
	t_big		*big;

	philo = (t_philo *) arg;
	big = philo->big;
	if ((philo->id + 1) % 2)
		custom_usleep(big->tte);
	while (1)
	{
		pthread_mutex_lock(&big->all_stop_mutex);
		if (!philos_all_eaten(big) && philos_all_alive(big))
		{
			pthread_mutex_unlock(&big->all_stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&big->all_stop_mutex);
		be_eating(philo);
		print_msgs(philo, SLEEPING);
		custom_usleep(big->tts);
		print_msgs(philo, THINKING);
	}
	return (NULL);
}
static int	whatsup_helper(t_big *big)
{
	int	i;

	i = big->all_alive;
	pthread_mutex_unlock(&big->all_stop_mutex);
	return (i);
}
void	whatsup(t_philo *phil_arr, t_big *big)
{
	int	i;

	while (philos_all_eaten(big))
	{
		i = 0;
		pthread_mutex_lock(&big->all_stop_mutex);
		while (i < big->headcount && philos_all_alive(big))
		{
			pthread_mutex_unlock(&big->all_stop_mutex);
			pthread_mutex_lock(&big->eating_mutex);
			if ((get_starttime() - phil_arr[i].last_eaten) >= big->ttd)
			{
				print_msgs(phil_arr + i, DIED);
				big->all_alive = false;
			}
			pthread_mutex_unlock(&big->eating_mutex);
			i++;
			pthread_mutex_lock(&big->all_stop_mutex);
		}
		if (whatsup_helper(big))
			break ;
		philos_all_eaten(big);
	}
}

int	philos_all_eaten(t_big *big)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	pthread_mutex_lock(&(big->cycle_mutex));
	while (++i < big->headcount)
	{
		if (big->phil_arr[i].times_eaten >= big->cycle)
			count++;
	}
	pthread_mutex_unlock(&(big->cycle_mutex));
	if (count == big->headcount)
		return (1);
	return (0);
}

int	philos_all_alive(t_big *big)
{
	pthread_mutex_lock(&(big->alive_mutex));
	if (!big->all_alive)
	{
		pthread_mutex_unlock(&(big->alive_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(big->alive_mutex));
	return (1);	
}
