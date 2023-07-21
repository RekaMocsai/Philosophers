/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:41 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/21 11:08:57 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork->fork_mutex);
	if (*(philo->l_fork->in_use) == 0)
		*(philo->l_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
	if (philo->l_fork->fork_mutex == philo->r_fork->fork_mutex) //Only one philo
	{
		custom_usleep(philo->big->ttd);
		return ;
	}
	pthread_mutex_lock(philo->r_fork->fork_mutex);
	if (*(philo->r_fork->in_use) == 0)
		*(philo->r_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
}

void	be_eating(t_philo *philo)
{
	pick_up_fork(philo);
	pthread_mutex_lock(&philo->big->eating_mutex);
	print_msgs(philo, EATING);
	philo->last_eaten = get_starttime();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->big->eating_mutex);
	custom_usleep(philo->big->tte);
	if (*(philo->l_fork->in_use) == 1)
		*(philo->l_fork->in_use) = 0;
	pthread_mutex_unlock(philo->l_fork->fork_mutex);
	if (philo->l_fork->fork_mutex  != philo->r_fork->fork_mutex)
	{
		if (*(philo->r_fork->in_use) == 1)
			*(philo->r_fork->in_use) = 0;
		pthread_mutex_unlock(philo->r_fork->fork_mutex);
	}
}
