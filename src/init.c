/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/14 18:38:05 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_mainstruct(int ac, char **av, t_big *big)
{
	big->headcount = ft_atoi(av[1]);
	big->ttd = ft_atoi(av[2]);
	big->tte = ft_atoi(av[3]);
	big->tts = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (av[5] && av[5][0] == '0')
		{
			printf("Invalid entry\n");
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

// static int	create_fork_mutex(t_big *big)
// {
// 	int				i;
// 	t_fork			*forks;
// 	pthread_mutex_t	*fork_mutex;

// 	fork_mutex = malloc(sizeof(pthread_mutex_t) * big->headcount);
// 	i = -1;
// 	if (!forks)
// 	{
// 		printf("Error allocating memory for forks\n");
// 		return (1);
// 	}
// 	while (++i < big->headcount)
// 	{
// 		if (pthread_mutex_init(forks + i, NULL) != 0)
// 			return (free_return_one(forks));
// 	}
/* 	if (pthread_mutex_init(&big->print_mutex, NULL) != 0 || \
 	pthread_mutex_init(&big->eating_mutex, NULL) != 0 || \
 	pthread_mutex_init(&big->lock_stop_all_eat, NULL) != 0)
 		return (free_return_one(forks));
*/
// 	big->forks = forks;
// 	return (0);
// }

// int	init_mutexes(t_big *big)
// {
// 	big->philos = malloc (sizeof (t_philo) * big->headcount);
// 	if (!big->philos)
// 		return (1);
// 	big->forks = create_fork_mutex(big);
	
// 	init_philos(big);
// 	return (0);
// }

// int	create_threads(t_big *big)
// {
	
// }