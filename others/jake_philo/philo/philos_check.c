/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:07:13 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/05 15:05:26 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_eaten(t_arg_info *info)
{
	int	i;

	i = -1;
	while (++i < info->phil_nbr)
	{
		if (info->phil_ptr[i].done_eating == 0)
			return (0);
	}
	return (1);
}

int	philos_alive(t_arg_info *info)
{
	int	i;

	i = -1;
	while (++i < info->phil_nbr)
	{
		if (info->phil_ptr[i].is_dead == 1)
			return (0);
	}
	return (1);
}
