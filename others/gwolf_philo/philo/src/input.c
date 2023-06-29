/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:08:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 15:09:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/**
 * @brief Check number of args.
 *
 * @param argc Argc received by main.
 * @return t_err SUCCESS, ERR_NUMARGS
 */
t_err	ft_counts_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("🔥 Expected 4 [5] args, got: %d\n", argc - 1);
		return (ERR_NUMARGS);
	}
	return (SUCCESS);
}

/**
 * @brief Check args of conformity.
 *
 * ft_count_args() for arg number.
 * Loop through the argv array.
 * If empty string is found return.
 * ft_isdigit() to check if string has only digits.
 *
 * @param argc Argc received by main.
 * @param argv Argv received by main.
 * @return t_err SUCCESS, ERR_NUMARGS, ERR_EMPTY_STR, ERR_NOTDIGIT
 */
t_err	ft_check_args(int argc, char **argv)
{
	uint32_t	i;
	t_err		err;

	err = ft_counts_args(argc);
	if (err != SUCCESS)
		return (err);
	while (argc-- > 1)
	{
		i = 0;
		if (argv[argc][i] == '\0')
		{
			printf("🔥 Empty string: %s (%d)\n", argv[argc], argc);
			return (ERR_EMPTY_STR);
		}
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i]) != SUCCESS)
			{
				printf("🔥 Not digit: %s (%d)\n", argv[argc], argc);
				return (ERR_NOTDIGIT);
			}
			i++;
		}
	}
	return (SUCCESS);
}

/**
 * @brief Convert args into nums and check them.
 *
 * Convert with ft_str_to_digit() which checks for overflow.
 * If 5 arguments convert it and set bool meals to true.
 * If num_philos or times_to_eat equals zero return error.
 *
 * @param params Pointer to struct containing params.
 * @param argc Argc received my main.
 * @param argv Argv received by main.
 * @param meals Is set to true if 5 args received.
 * @return t_err SUCCESS, ERR_OVERFLOW, ERR_ISZERO
 */
t_err	ft_set_params(t_params *params, int argc, char **argv, bool *meals)
{
	t_err	err;

	err = ft_str_to_digit(argv[1], &params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_str_to_digit(argv[2], &params->time_to_die);
	if (err != SUCCESS)
		return (err);
	err = ft_str_to_digit(argv[3], &params->time_to_eat);
	if (err != SUCCESS)
		return (err);
	err = ft_str_to_digit(argv[4], &params->time_to_sleep);
	if (err != SUCCESS)
		return (err);
	if (argc == 6)
	{
		err = ft_str_to_digit(argv[5], &params->times_to_eat);
		if (err != SUCCESS)
			return (err);
		*meals = true;
	}
	if (params->num_philos == 0
		|| (argc == 6 && params->times_to_eat == 0))
		return (ERR_ISZERO);
	return (SUCCESS);
}
