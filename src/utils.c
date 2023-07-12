/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/12 11:17:15 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;

	i = 0;
	nb = 0;
	while (str && str[i] && i < 11)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return (nb);
}

// int	still_alive(t_big *big)
// {
// 	pthread_mutex_lock(&(big->alive_mutex));
// 	if (!big->all_alive)
// 	{
// 		pthread_mutex_unlock(&(big->alive_mutex));
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&(big->alive_mutex));
// 	return (1);
// }
