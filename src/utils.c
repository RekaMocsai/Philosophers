/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/25 15:15:32 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	ft_atoi(const char *str)
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
		return (0);
	return (nb);
}

int	print_msgs(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->big->print_mutex);
	if (philos_all_alive(philo->big) && !philos_all_eaten(philo->big))
	{
		if (i == TAKEN_FORK)
			printf("%ld %d has taken a fork\n", \
			get_starttime() - philo->big->start_time, philo->id + 1);
		else if (i == EATING)
			printf("%ld %d is eating\n", \
			get_starttime() - philo->big->start_time, philo->id + 1);
		else if (i == SLEEPING)
			printf("%ld %d is sleeping\n", \
			get_starttime() - philo->big->start_time, philo->id + 1);
		else if (i == THINKING)
			printf("%ld %d is thinking\n", \
			get_starttime() - philo->big->start_time, philo->id + 1);
		else if (i == DIED)
			printf("%ld %d died\n", \
			get_starttime() - philo->big->start_time, philo->id + 1);
		pthread_mutex_unlock(&philo->big->print_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->big->print_mutex);
	return (1);
}
