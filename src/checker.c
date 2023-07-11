/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/11 15:36:04 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Returns 1 if current char is digit, 0 if anithing else */
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	check_args(int argc, char **argv)
{
	int i;

	while (argc-- > 1)
	{
		i = 0;
		if (argv[argc][i] == '\0')
		{
			printf("Empty string is not accepted!\n");
			return (1);
		}
		while (argv[argc][i])
		{
			if (!ft_isdigit(argv[argc][i]))
			{
				printf("Arguments have to be digits only!\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}


int	input_checker(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf(
			"Wondering how to use?\nType: ./philo number_of_philosophers " \
			"time_to_die " \
			"time_to_eat " \
			"time_to_sleep " \
			"[number_of_times_each_philosopher_must_eat]\n"
			"Times are in ms. Only positive numbers alloved! " \
			"- args might be subjected to limitations, " \
			"but feel free to play around!\n");
		return (1);
	}
	if (check_args(argc, argv))
		return (1);
	return (0);
}

// int	invalid_nums(t_main *main)
// {
// 	int	invalid;

// 	invalid = 0;
// 	if (main->nr < 1)
// 		invalid++;
// 	if (main->ttd < 0)
// 		invalid++;
// 	if (main->tte < 0)
// 		invalid++;
// 	if (main->tts < 0)
// 		invalid++;
// 	if (main->cycle < 0)
// 		invalid++;
// 	if (invalid)
// 		free(data);
// 	return (invalid);
// }