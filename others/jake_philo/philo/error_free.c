/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:10:04 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/05 15:22:26 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	usage_message(t_arg_info *info)
{
	printf("Usage: ./phils num die eat sleep [must_eaten]\n");
	printf("[] Argument is optional.\n");
	free(info);
	return (-1);
}

int	error_occured(t_arg_info *info)
{
	printf("Error\n");
	return (free_all(info));
}

int	free_all(t_arg_info *info)
{
	if (info->forks)
		free(info->forks);
	if (info->phil_ptr)
		free(info->phil_ptr);
	destroy_mutex(info);
	free(info);
	return (-1);
}
