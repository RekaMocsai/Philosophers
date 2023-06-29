/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:45:51 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 13:42:49 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_arg_info(t_arg_info *info, int argc, char **argv)
{
	gettimeofday(&info->start_time, NULL);
	argc -= 1;
	if (argc < 4 || argc > 5)
		return (-1);
	info->phil_nbr = modified_atoi(argv[1]);
	info->time_die = modified_atoi(argv[2]);
	info->time_eat = modified_atoi(argv[3]);
	info->time_sleep = modified_atoi(argv[4]);
	if (argc == 5)
		info->times_must_eaten = modified_atoi(argv[5]);
	else
		info->times_must_eaten = -1;
	if (info->phil_nbr <= 0 || info->time_die <= 0 || info->time_eat <= 0
		|| info->time_sleep <= 0)
		return (-1);
	if (argc == 5 && info->times_must_eaten <= 0)
		return (-1);
	return (0);
}

int	modified_atoi(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[0] == '+')
		str++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret = ret * 10 + str[i] - '0';
			i++;
		}
		else
			return (-1);
	}
	return (ret);
}
