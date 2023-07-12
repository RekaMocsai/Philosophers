/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/12 11:19:05 by rmocsai          ###   ########.fr       */
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
	big->nr = ft_atoi(av[1]);
	big->ttd = ft_atoi(av[2]);
	big->tte = ft_atoi(av[3]);
	big->tts = ft_atoi(av[4]);
	if (ac == 6)
		big->cycle = ft_atoi(av[5]);
	else
		big->cycle = -1;
	invalid_entry(big);
	return (big);
}
