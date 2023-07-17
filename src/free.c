/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:03:16 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/17 14:36:37 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_fork_mutexes(t_big *big)
{
	int	i;

	i = -1;
	while (++i < big->headcount)
	{
		if (pthread_mutex_destroy(big->fork_mutex_arr + i))
			return (1);
	}
	safe_free(big->fork_mutex_arr);
	return (0);
}