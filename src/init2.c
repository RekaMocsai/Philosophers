/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:25:44 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/28 18:18:25 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_forks(t_big *big)
{
	int				i;

	big->fork_arr = malloc (sizeof (int) * big->headcount);
	if (!big->fork_arr)
	{
		print_errors("Fork_arr malloc error!\n", 2);
		return (1);
	}
	i = -1;
	while (++i < big->headcount)
		big->fork_arr[i] = 0;
	return (0);
}

int	init_philos(t_big *big)
{
	int	i;

	i = -1;
	while (++i < big->headcount)
	{
		big->phil_arr[i].id = i;
		big->phil_arr[i].big = big;
		big->phil_arr[i].start_time = 0;
		big->phil_arr[i].times_eaten = 0;
		big->phil_arr[i].l_fork = &(big->forks[i]);
		big->phil_arr[i].r_fork = &(big->forks[(i + 1) % big->headcount]);
	}
	return (0);
}

int	init_bigstruct(int ac, char **av, t_big *big)
{
	big->all_alive = true;
	big->headcount = ft_atoi(av[1]);
	big->ttd = ft_atoi(av[2]);
	big->tte = ft_atoi(av[3]);
	big->tts = ft_atoi(av[4]);
	if (!big->headcount || !big->ttd || !big->tte || !big->tts)
	{
		print_errors("Invalid entry!\n", 2);
		return (1);
	}
	if (ac == 6)
	{
		if ((av[5] && av[5][0] == '0') || !ft_atoi(av[5]))
		{
			print_errors("Invalid entry\n", 2);
			return (1);
		}
		big->cycle = ft_atoi(av[5]);
	}
	else
		big->cycle = 0;
	if (invalid_entry_check(big))
		return (1);
	return (0);
}
