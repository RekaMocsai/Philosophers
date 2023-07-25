/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:15:28 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/24 10:37:21 by rmocsai          ###   ########.fr       */
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

void	custom_usleep(unsigned long time)
{
	unsigned long	start;

	start = get_starttime();
	usleep(time * 990);
	while (get_starttime() - start < time)
		usleep(time);
}
