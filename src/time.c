/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:15:28 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/27 10:21:59 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* gets system clock time in 2 members: timeval.tv_sec is in seconds, 
timeval.tv_usec is in microseconds. converts them to millisec
 and adds them up. Returns 0 if gettimeofday fails */
unsigned long	get_starttime(void)
{
	struct timeval	time_val;

	if (gettimeofday(&time_val, NULL) == 0)
		return ((time_val.tv_sec * 1000) + (time_val.tv_usec / 1000));
	else
		return (0);
}

/* makes sure it doesn't eat || sleep if someone is already dead! */
int	custom_usleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = get_starttime();
	while ((get_starttime() - start) < time)
	{
		if (!philos_all_alive(philo->big))
			return (1);
		usleep(100);
	}
	return (0);
}
