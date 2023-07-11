/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/11 13:42:29 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_atoi(const char *str, int *ptr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str && str[i] && i < 11)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > INT_MAX)
		return (1);
	*ptr = (int)num;
	return (0);
}

