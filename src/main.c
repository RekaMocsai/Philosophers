/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/25 15:23:37 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_big	big;

	if (input_checker(argc, argv) || init_bigstruct(argc, argv, &big))
		return (1);
	if (init_main(&big) || create_threads(big.phil_arr))
	{
		printf("If no other message: memory allocation failed\n");
		//free_all_safely(&big);
		return (2);
	}
	return (0);
}
