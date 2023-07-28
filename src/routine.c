/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:41 by rmocsai           #+#    #+#             */
/*   Updated: 2023/07/28 18:13:06 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* routine all threads follow (1 for each philo) 
 - every even nr id has a delay to not reach at same time
 - eating
 - sleeping
 - thinking 
 
 exits when during printing all_alive is false or all have eaten per cycle
    - also monitored by whatsup function on main process */
void	*workwork(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	if ((philo->id + 1) % 2 == 0)
		usleep(50);
	while (1)
	{
		if (be_eating(philo))
			break ;
		if (print_msgs(philo, SLEEPING))
			break ;
		if (custom_usleep(philo->big->tts, philo))
			break ;
		usleep(75);
		if (print_msgs(philo, THINKING))
			break ;
	}
	return (NULL);
}

static void	pick_up_rfork(t_philo *philo)
{
	usleep(225);
	pthread_mutex_lock(philo->r_fork->fork_mutex);
	if (*(philo->r_fork->in_use) == 0)
		*(philo->r_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
	if (philo->r_fork->fork_mutex == philo->l_fork->fork_mutex)
	{
		custom_usleep(philo->big->ttd + 10, philo);
		return ;
	}
	pthread_mutex_lock(philo->l_fork->fork_mutex);
	if (*(philo->l_fork->in_use) == 0)
		*(philo->l_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
}

static void	pick_up_lfork(t_philo *philo)
{
	usleep(225);
	pthread_mutex_lock(philo->l_fork->fork_mutex);
	if (*(philo->l_fork->in_use) == 0)
		*(philo->l_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
	if (philo->l_fork->fork_mutex == philo->r_fork->fork_mutex)
	{
		custom_usleep(philo->big->ttd + 10, philo);
		return ;
	}
	pthread_mutex_lock(philo->r_fork->fork_mutex);
	if (*(philo->r_fork->in_use) == 0)
		*(philo->r_fork->in_use) = 1;
	print_msgs(philo, TAKEN_FORK);
}

/* Be_eating was too long :)  */
static void	run_the_helper(t_philo *philo)
{
	print_msgs(philo, EATING);
	pthread_mutex_lock(&philo->big->alive_mutex);
	philo->last_eaten = get_starttime();
	pthread_mutex_unlock(&philo->big->alive_mutex);
	pthread_mutex_lock(&philo->big->cycle_mutex);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->big->cycle_mutex);
}

/* Determines righthanded (odd) and lefthanded (even) philos
Does the eating part: 
 - pick up both forks, 
 - usleep till tte,
 - put down both forks */
int	be_eating(t_philo *philo)
{
	if ((philo->id + 1) % 2)
		pick_up_rfork(philo);
	else
		pick_up_lfork(philo);
	run_the_helper(philo);
	if (custom_usleep(philo->big->tte, philo))
	{
		pthread_mutex_unlock(philo->l_fork->fork_mutex);
		if (philo->l_fork->fork_mutex != philo->r_fork->fork_mutex)
			pthread_mutex_unlock(philo->r_fork->fork_mutex);
		return (1);
	}
	if (*(philo->l_fork->in_use) == 1)
		*(philo->l_fork->in_use) = 0;
	pthread_mutex_unlock(philo->l_fork->fork_mutex);
	if (philo->l_fork->fork_mutex != philo->r_fork->fork_mutex)
	{
		if (*(philo->r_fork->in_use) == 1)
			*(philo->r_fork->in_use) = 0;
		pthread_mutex_unlock(philo->r_fork->fork_mutex);
	}
	return (0);
}
