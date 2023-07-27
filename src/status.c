/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:52:23 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/27 10:09:24 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philos_all_eaten(t_big *big)
{
	int	i;
	int	count;

	if (!big->cycle)
		return (0);
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
	if (big->all_alive == false)
	{
		pthread_mutex_unlock(&(big->alive_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(big->alive_mutex));
	return (1);
}
