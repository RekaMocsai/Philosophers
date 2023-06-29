/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:54:07 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 16:15:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Converts a string to digit.
 *
 * Expects only digits, has no error checks for not digit.
 * If resulting num is bigger than int_max return error.
 *
 * @param str String to convert.
 * @param ret Pointer where to save.
 * @return t_err SUCCESS, ERR_OVERFLOW
 */
t_err	ft_str_to_digit(const char *str, int32_t *ret)
{
	uint8_t	i;
	int64_t	num;

	i = 0;
	num = 0;
	while (str[i] && i < 11)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > INT32_MAX)
		return (ERR_OVERFLOW);
	*ret = (int32_t)num;
	return (SUCCESS);
}

/**
 * @brief Checks if char is digit.
 *
 * @param c Char to check.
 * @return t_err SUCCESS, ERR_NOTDIGIT
 */
t_err	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	else
		return (ERR_NOTDIGIT);
}

/**
 * @brief Returns a timestamp in milliseconds of current time.
 *
 * @return int64_t Timestamp in ms
 */
int64_t	ft_timestamp_in_ms(void)
{
	struct timeval	tv;
	int64_t			ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

/**
 * @brief Wrapper around usleep to make it a bit more precise.
 *
 * Calc the start time using ft_timestamp_in_ms()
 * In an infinte loop check if time has elapsed.
 * If not usleep for 100 microseconds.
 *
 * @param time_in_ms Time to wait in ms
 */
void	ft_wrapper_usleep(int64_t time_in_ms)
{
	int64_t	start_time;

	start_time = ft_timestamp_in_ms();
	while ((ft_timestamp_in_ms() - start_time - time_in_ms) < 0)
		usleep(100);
}
