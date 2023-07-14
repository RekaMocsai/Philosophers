/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/14 18:37:21 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_big	big;
	
	big.all_alive = true;
	big.all_full = false;
	if (input_checker(argc, argv) || init_mainstruct(argc, argv, &big))
		return (1);
	// if (!init_mutexes(&big) || !create_threads(&big))
	// {
	// 	printf("Memory allocation failed\n");
	// 	return (1);
	// }
	gettimeofday(&(big.start_time), NULL);
	return (0);
}
