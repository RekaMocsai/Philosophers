/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:03:16 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/24 11:47:32 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	safe_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
	ptr = NULL;
}

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
