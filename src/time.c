/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:15:28 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/18 16:01:46 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int get_starttime(unsigned long *start_time)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 0)
	{
		start_time = (unsigned long *)(time.tv_sec * 1000) + (time.tv_usec / 1000);
		return (0);
	}
	else
		return (1);
}
