/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:30:10 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 14:01:05 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_mutex(t_arg_info *info)
{
	int	i;

	i = -1;
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->phil_nbr);
	while (++i < info->phil_nbr)
	{
		pthread_mutex_init(&info->fork_mutex[i], NULL);
	}
	pthread_mutex_init(&info->print_mutex, NULL);
}

void	destroy_mutex(t_arg_info *info)
{
	int	i;

	i = -1;
	while (++i < info->phil_nbr)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
	}
	free(info->fork_mutex);
	pthread_mutex_destroy(&info->print_mutex);
}
