/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:44:26 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/27 10:22:27 by rmocsai          ###   ########.fr       */
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

void	print_errors(char *str, int fd)
{
	unsigned int	i;

	i = 0;
	if (!str || !fd)
		return ;
	while (str[i] != '\0')
	{
		write(fd, str + i, sizeof(str[i]));
		i++;
	}
}

int	destroy_return_one(pthread_mutex_t *forks, int i)
{
	int	y;

	y = -1;
	while (++y < i)
	{
		if (pthread_mutex_destroy(&forks[y]))
		{
			print_errors("System failure - can't destroy mutexes\n", 2);
			break ;
		}
	}
	return (1);
}

int	destroy_check(pthread_mutex_t *ptr)
{
	if (ptr != NULL)
	{
		if (pthread_mutex_destroy(ptr))
			print_errors("System failure - can't destroy mutexes\n", 2);
	}
	return (1);
}

int	join_successful_threads(int i, t_philo *phil_arr)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		if (pthread_join(phil_arr[i].tid, NULL))
			print_errors("System failure - unsuccesful at joining threads\n", 2);
	}
	return (1);
}
