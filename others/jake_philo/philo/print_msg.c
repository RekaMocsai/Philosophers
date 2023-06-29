/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:57:42 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/05 15:06:34 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msgs(t_phil *phil, int index)
{
	pthread_mutex_lock(&phil->info->print_mutex);
	if (philos_eaten(phil->info) == 0 && philos_alive(phil->info) == 1)
	{
		if (index == 1)
			printf("%ld %d has taken a fork\n", calc_timestamp(phil->info),
				phil->id + 1);
		if (index == 2)
			printf("%ld %d is eating\n", calc_timestamp(phil->info), phil->id
				+ 1);
		if (index == 3)
			printf("%ld %d is sleeping\n", calc_timestamp(phil->info), phil->id
				+ 1);
		if (index == 4)
			printf("%ld %d is thinking\n", calc_timestamp(phil->info), phil->id
				+ 1);
		if (index == 5)
			printf("%ld %d died\n", calc_timestamp(phil->info), phil->id + 1);
	}
	pthread_mutex_unlock(&phil->info->print_mutex);
}
