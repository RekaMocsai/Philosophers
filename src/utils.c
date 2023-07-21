/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/20 12:48:07 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long ft_atoi(const char *str)
{
	int				i;
	unsigned long			nb;

	i = 0;
	nb = 0;
	while (str && str[i] && i < 11)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb > INT_MAX)
		return (0);
	return (nb);
}

void	stop_all(t_big *big)
{
	pthread_mutex_lock(&(big->alive_mutex));
	big->all_alive = 0;
	pthread_mutex_unlock(&(big->alive_mutex));
}


void	print_msgs(t_philo *philo, int i)
{
	t_big	*big;
	
	big = philo->big;
	pthread_mutex_lock(&big->print_mutex);
	if (!philos_all_eaten(big) && philos_all_alive(big))
	{
		if (i == TAKEN_FORK)
 			printf("%ld %d has taken a fork\n", get_starttime() - big->start_time, philo->id + 1);
		if (i == EATING)
			printf("%ld %d is eating\n", get_starttime() - big->start_time, philo->id + 1);
		if (i == SLEEPING)
			printf("%ld %d is sleeping\n", get_starttime() - big->start_time, philo->id + 1);
		if (i == THINKING)
			printf("%ld %d is thinking\n", get_starttime() - big->start_time, philo->id + 1);
		if (i == DIED)
			printf("%ld %d died\n", get_starttime() - big->start_time, philo->id + 1);
	}
	pthread_mutex_unlock(&big->print_mutex);
}

