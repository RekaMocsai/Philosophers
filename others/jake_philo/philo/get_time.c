/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:17:32 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/05 15:04:56 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	calc_timestamp(t_arg_info *info)
{
	unsigned long long	timestamp;
	struct timeval		cur;

	timestamp = 0;
	gettimeofday(&cur, NULL);
	timestamp = info->start_time.tv_sec * 1000000 + info->start_time.tv_usec;
	timestamp = (cur.tv_sec * 1000000 + cur.tv_usec) - timestamp;
	return (timestamp / 1000);
}

long	calc_if_dead(t_phil *phil)
{
	struct timeval	cur;
	int				cur_ms;
	int				phil_ms;

	gettimeofday(&cur, NULL);
	cur_ms = (cur.tv_sec * 1000000 + cur.tv_usec) / 1000;
	phil_ms = (phil->time_till_death.tv_sec * 1000000
			+ phil->time_till_death.tv_usec) / 1000;
	if (cur_ms - phil_ms > phil->info->time_die)
		return (1);
	return (0);
}
