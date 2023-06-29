/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:15:31 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 14:02:19 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_forks(t_phil *phil)
{
	if (phil->id == 0)
		pthread_mutex_lock(&phil->info->fork_mutex[phil->info->phil_nbr - 1]);
	else
		pthread_mutex_lock(&phil->info->fork_mutex[phil->id - 1]);
	pthread_mutex_lock(&phil->info->fork_mutex[phil->id]);
	if (*phil->l_fork == 0 && *phil->r_fork == 0)
	{
		*phil->l_fork = 1;
		*phil->r_fork = 1;
		phil->has_forks = 1;
	}
	if (phil->id == 0)
		pthread_mutex_unlock(&phil->info->fork_mutex[phil->info->phil_nbr - 1]);
	else
		pthread_mutex_unlock(&phil->info->fork_mutex[phil->id - 1]);
	pthread_mutex_unlock(&phil->info->fork_mutex[phil->id]);
}

void	eat(t_phil *phil)
{
	if (phil->has_forks == 1)
	{
		print_msgs(phil, 1);
		print_msgs(phil, 1);
		print_msgs(phil, 2);
		phil->times_eaten = phil->times_eaten + 1;
		gettimeofday(&phil->time_till_death, NULL);
		usleep(phil->info->time_eat * 1000);
		*phil->l_fork = 0;
		*phil->r_fork = 0;
		phil->has_forks = 0;
		print_msgs(phil, 3);
		usleep(phil->info->time_sleep * 1000);
		print_msgs(phil, 4);
		usleep(1000);
	}
}

void	*eat_sleep_repeat(t_phil *phil)
{
	gettimeofday(&phil->time_till_death, NULL);
	while (philos_eaten(phil->info) == 0 && philos_alive(phil->info) == 1)
	{
		if (phil->info->times_must_eaten != -1
			&& phil->info->times_must_eaten == phil->times_eaten)
		{
			phil->done_eating = 1;
			break ;
		}
		check_forks(phil);
		eat(phil);
		usleep(10);
	}
	return (NULL);
}

void	check_phil_times(t_arg_info *info)
{
	int	i;

	while (philos_eaten(info) == 0 && philos_alive(info) == 1)
	{
		i = -1;
		while (++i < info->phil_nbr)
		{
			if (calc_if_dead(&info->phil_ptr[i]) == 1
				&& info->phil_ptr[i].times_eaten != info->times_must_eaten)
			{
				info->phil_ptr[i].is_dead = 1;
				pthread_mutex_lock(&info->print_mutex);
				printf("%ld %d died\n", calc_timestamp(info),
					info->phil_ptr[i].id + 1);
				pthread_mutex_unlock(&info->print_mutex);
				break ;
			}
		}
		usleep(50);
	}
}
