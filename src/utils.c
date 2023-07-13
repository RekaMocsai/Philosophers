/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/13 11:23:03 by rmocsai          ###   ########.fr       */
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

void	print_msgs(t_big *big, int i)
{
	pthread_mutex_lock(&big->print_mutex);
	if (philos_all_eaten(big) == 0 && philos_all_alive(big) == 1)
	{
		if (i == TAKEN_FORK)
			printf("%ld %d has taken a fork\n", calc_timestamp(big), \
			philos->id + 1);
		if (i == EATING)
			printf("%ld %d is eating\n", calc_timestamp(big), philos->id + 1);
		if (i == SLEEPING)
			printf("%ld %d is sleeping\n", calc_timestamp(big), philos->id + 1);
		if (i == THINKING)
			printf("%ld %d is thinking\n", calc_timestamp(big), philos->id + 1);
		if (i == DIED)
			printf("%ld %d died\n", calc_timestamp(big), philos->id + 1);
	}
	pthread_mutex_unlock(&big->print_mutex);
}

philos_all_eaten(t_big *big)
{}

philos_all_alive(t_big *big)
{
	
}

long calc_timestamp(t_big *big)
{
	unsigned long	timestamp;
	struct timeval		current;

	timestamp = 0;
	gettimeofday(&current, NULL);
	timestamp = big->start_time.tv_sec * 1000000 + big->start_time.tv_usec;
	timestamp = (current.tv_sec * 1000000 + current.tv_usec) - timestamp;
	return (timestamp / 1000);
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
