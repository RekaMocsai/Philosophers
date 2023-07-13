/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/13 11:23:08 by rmocsai          ###   ########.fr       */
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

/* Checks for empty strings & if args are digits only */
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

/* Returns 1 if input is incorrect - error msg already printed! */
int	input_checker(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf(
			"Wondering how to use?\nType: ./philo number_of_philosophers " \
			"time_to_die " \
			"time_to_eat " \
			"time_to_sleep " \
			"[Optional: number_of_times_each_philosopher_must_eat]\n"
			"Times are in ms. Only positive numbers alloved! " \
			"- args might be subjected to limitations, " \
			"but feel free to play around!\n");
		return (1);
	}
	if (check_args(argc, argv))
		return (1);
	return (0);
}

/* checks for invalid entries - intmax or zeros... */
void	invalid_entry_check(t_big *big)
{
	int	i;

	i = 0;
	if (big->headcount < 1 || big->headcount > 200)
		i++;
	if (big->ttd < 1)
		i++;
	if (big->tte < 1)
		i++;
	if (big->tts < 1)
		i++;
	if (i)
	{
		printf("Invalid entry\n");
		free(big);
		exit (1);
	}
}
