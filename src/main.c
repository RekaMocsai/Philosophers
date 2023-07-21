/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/19 11:39:59 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_big	big;
	
	big.all_alive = true;
	big.all_full = false;
	big.start_time = get_starttime();
	if (input_checker(argc, argv) || init_bigstruct(argc, argv, &big) || \
	!big.start_time)
		return (1);
	if (init_main(&big) || create_threads(big.phil_arr))
	{
		printf("If no other message: memory allocation failed\n");
		//free_all_safely(&big);
		return (1);
	}
	// if ()
	// 	return (1);
	return (0);
}
