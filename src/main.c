/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/25 17:43:05 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_big	big;

	if (input_checker(argc, argv) || init_bigstruct(argc, argv, &big))
		return (1);
	if (init_main(&big))
	{
		printf("If no other message: memory allocation failed\n");
		return (2);
	}
	if (create_threads(big.phil_arr))
	{
		printf("pthread join or create failed\n");
		free_all_safely(&big);
		return (3);
	}
	return (0);
}
