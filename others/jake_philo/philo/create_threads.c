/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:04:12 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 13:42:40 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_info_vars(t_arg_info *info)
{
	int	i;

	info->forks = malloc(sizeof(int) * info->phil_nbr);
	if (!info->forks)
		return (-1);
	memset(info->forks, 0, sizeof(int) * info->phil_nbr);
	i = -1;
	while (++i < info->phil_nbr)
	{
		if (i == 0)
		{
			info->phil_ptr[i].l_fork = &info->forks[info->phil_nbr - 1];
			info->phil_ptr[i].r_fork = &info->forks[i];
		}
		else
		{
			info->phil_ptr[i].l_fork = &info->forks[i - 1];
			info->phil_ptr[i].r_fork = &info->forks[i];
		}
		info->phil_ptr[i].id = i;
		info->phil_ptr[i].info = info;
	}
	return (0);
}

int	create_threads(t_arg_info *info)
{
	int	i;

	info->phil_ptr = malloc(sizeof(t_phil) * info->phil_nbr);
	if (info->phil_ptr == NULL)
		return (-1);
	memset(info->phil_ptr, 0, sizeof(t_phil) * info->phil_nbr);
	if (init_info_vars(info) == -1)
		return (-1);
	i = -1;
	while (++i < info->phil_nbr)
	{
		if (pthread_create(&info->phil_ptr[i].thread, NULL,
				(void *)&eat_sleep_repeat, &info->phil_ptr[i]) != 0)
			return (-1);
	}
	return (0);
}

int	join_all(t_arg_info *info)
{
	int	i;

	i = -1;
	while (++i < info->phil_nbr)
	{
		if (pthread_join(info->phil_ptr[i].thread, NULL) != 0)
			return (-1);
	}
	return (0);
}
