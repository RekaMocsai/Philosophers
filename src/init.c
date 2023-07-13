/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/13 11:23:09 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_big *init_mainstruct(int ac, char **av)
{
	t_big	*big;
	
	big = malloc(sizeof (t_big));
	if (big == NULL)
	{
		printf("Memory allocation failed\n");
		return (NULL);
	}
	big->headcount = ft_atoi(av[1]);
	big->ttd = ft_atoi(av[2]);
	big->tte = ft_atoi(av[3]);
	big->tts = ft_atoi(av[4]);
	if (ac == 6)
		big->cycle = ft_atoi(av[5]);
	else
		big->cycle = 0;
	invalid_entry_check(big);
	return (big);
}

int	create_threads(t_big *big)
{
	big->philos = malloc (sizeof (t_philo) * big->headcount);
	if (!big->philos)
		return (1);
	create_fork_mutex(big);
	
	init_philos(big);
	return (0);
}

int	create_fork_mutex(t_big *big)
{
	int				i;
	pthread_mutex_t	*forkslist;

	forkslist = malloc(sizeof(pthread_mutex_t) * big->headcount);
	i = -1;
	if (!forkslist)
	{
		printf("Error allocating memory for forks\n");
		return (1);
	}
	while (++i < big->headcount)
	{
		if (pthread_mutex_init(forkslist + i, NULL) != 0)
			return (free_return_one(forkslist));
	}
	if (pthread_mutex_init(&big->print_mutex, NULL) != 0 || \
	pthread_mutex_init(&big->eating_mutex, NULL) != 0 || \
	pthread_mutex_init(&rules->lock_stop_all_eat, NULL) != 0)
		return (free_return_one(forkslist));
	big->forkslist = forkslist;
	return (0);
}