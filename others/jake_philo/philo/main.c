/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:15 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 13:45:57 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_arg_info	*info;

	info = malloc(sizeof(t_arg_info));
	if (!info)
		return (error_occured(info));
	if (get_arg_info(info, argc, argv) == -1)
		return (usage_message(info));
	if (info->phil_nbr == 1)
	{
		usleep(1000 * info->time_die);
		printf("%ld %d died\n", calc_timestamp(info), 1);
		free(info);
		return (0);
	}
	create_mutex(info);
	if (create_threads(info) == -1)
		return (error_occured(info));
	usleep(100000);
	check_phil_times(info);
	if (philos_eaten(info) == 1)
		printf("All Philosophers have eaten %d times\n",
			info->times_must_eaten);
	join_all(info);
	free_all(info);
	return (0);
}
