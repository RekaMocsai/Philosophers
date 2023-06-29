/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:32:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 16:01:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

/**
 * @brief Simulates eating of philo.
 *
 * Check if dead with ft_is_dead()
 * Take forks. Depending on ID % 2 left or righthanded.
 * ft_print() EAT.
 * ft_wrapper_usleep() for time_to_eat.
 * ft_update_philo_meals_ate().
 * ft_drop_forks().
 *
 * @param philo A philo.
 * @return t_err SUCCESS, STOP
 */
t_err	ft_eat(t_philo *philo)
{
	t_err	err;

	if (ft_is_dead(philo))
		return (STOP);
	if (philo->id % 2 == 0)
		err = ft_take_forks_lefthanded(philo);
	else
		err = ft_take_forks_righthanded(philo);
	if (err != SUCCESS)
		return (err);
	err = ft_update_philo_last_meal(philo);
	if (err != SUCCESS)
		return (err);
	ft_print(philo, EAT);
	ft_wrapper_usleep(philo->params->time_to_eat);
	err = ft_update_philo_meals_ate(philo);
	if (err != SUCCESS)
		return (err);
	err = ft_drop_forks(philo);
	if (err != SUCCESS)
		return (err);
	return (SUCCESS);
}

/**
 * @brief Simulates sleeping of philo.
 *
 * Check status with ft_get_philo_status().
 * ft_print() SLEEP.
 * ft_wrapper_usleep() with time_to_sleep.
 *
 * @param philo A philo.
 * @return t_err SUCCESS, STOP
 */
t_err	ft_sleep(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
		return (STOP);
	ft_print(philo, SLEEP);
	ft_wrapper_usleep(philo->params->time_to_sleep);
	return (SUCCESS);
}

/**
 * @brief Simluates thinking of philo.
 *
 * Check if dead with ft_is_dead().
 * Check status with ft_get_philo_status().
 * ft_print() THINK.
 *
 * @param philo A philo
 * @return t_err SUCCESS, STOP
 */
t_err	ft_think(t_philo *philo)
{
	t_status	status;

	if (ft_is_dead(philo))
		return (STOP);
	status = ACTIVE;
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
		return (STOP);
	ft_print(philo, THINK);
	return (SUCCESS);
}

void	ft_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	ft_wrapper_usleep(philo->params->time_to_die + 1);
	while (!ft_is_dead(philo))
		ft_wrapper_usleep(1);
	philo->left_fork->in_use = false;
	pthread_mutex_unlock(&philo->left_fork->m_in_use);
}

/**
 * @brief Simulates the life of a philo.
 *
 * Handle one philo with ft_single_philo().
 * Repeat until a function detects DEAD or FULL_STOP:
 * ft_eat(), ft_sleep(), ft_think.
 * @param arg
 * @return void*
 */
void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_philos == 1)
	{
		ft_single_philo(philo);
		return (NULL);
	}
	while (1)
	{
		if (ft_eat(philo) != SUCCESS)
			break ;
		if (ft_sleep(philo) != SUCCESS)
			break ;
		if (ft_think(philo) != SUCCESS)
			break ;
	}
	return (NULL);
}
