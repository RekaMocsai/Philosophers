/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/17 15:49:38 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_big	big;
	
	big.all_alive = true;
	big.all_full = false;
	if (input_checker(argc, argv) || init_bigstruct(argc, argv, &big))
		return (1);
	if (init_main(&big)) // || create_threads(&big))
	{
		printf("If no other message: memory allocation failed\n");
		//free philos, forks?
		return (1);
	}
	gettimeofday(&(big.start_time), NULL);
	return (0);
}
