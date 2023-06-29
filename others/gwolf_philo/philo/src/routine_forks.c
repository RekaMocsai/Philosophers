/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:27:29 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 15:37:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

/**
 * @brief Take forks starting with left one.
 *
 * Lock mutex. Check if dead.
 * If dead unlock mutex and return.
 * If active print and set in_use to true.
 * Do the same with other fork.
 * If dead drop both forks.
 * If active print and return SUCCESS
 *
 * @param philo A philo
 * @return t_err SUCCESS, STOP
 */
t_err	ft_take_forks_lefthanded(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (STOP);
	}
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		philo->left_fork->in_use = false;
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		return (STOP);
	}
	philo->right_fork->in_use = true;
	ft_print(philo, FORK);
	return (SUCCESS);
}

/**
 * @brief Take forks starting with right one.
 *
 * See ft_take_forks_lefthanded()
 *
 * @param philo A philo
 * @return t_err SUCCESS, STOP
 */
t_err	ft_take_forks_righthanded(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		return (STOP);
	}
	philo->right_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		philo->right_fork->in_use = false;
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (STOP);
	}
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	return (SUCCESS);
}

/**
 * @brief Drop both forks.
 *
 * Used after eating. Set in_use to false and mutex_unlock.
 *
 * @param philo A philo
 * @return t_err SUCCESS
 */
t_err	ft_drop_forks(t_philo *philo)
{
	philo->left_fork->in_use = false;
	pthread_mutex_unlock(&philo->left_fork->m_in_use);
	philo->right_fork->in_use = false;
	pthread_mutex_unlock(&philo->right_fork->m_in_use);
	return (SUCCESS);
}
