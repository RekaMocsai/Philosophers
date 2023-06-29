/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:11:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 15:28:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

/**
 * @brief Destroy mutex m_in_use in forks array.
 *
 * @param forks Forks array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_destroy_forks_in_use(t_fork *forks, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&forks[i].m_in_use) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Destroy mutex m_last_meal in philos array.
 *
 * @param philos Philos array.
 * @param num_philos Numer of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_destroy_philo_last_meal(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_last_meal) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Destroy mutex m_meals_ate in philos array.
 *
 * @param philos Philos array.
 * @param num_philos Numer of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_destroy_philo_meals_ate(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_meals_ate) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Destroy mutex m_status in philos array.
 *
 * @param philos Philos array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MUTEX_DESTROY
 */
t_err	ft_m_destroy_philo_status(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_status) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Driver ft to call several mutex destroys for philos.

 * ft_m_destroy_philos_last_meal().
 * ft_m_destroy_philos_meals_ate().
 * ft_m_destroy_philos_status().
 *
 * @param philos Philos array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MUTEX_DESTROY
 */
t_err	ft_m_destroy_philo(t_philo *philos, int32_t num_philos)
{
	t_err	err;

	err = ft_m_destroy_philo_status(philos, num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_m_destroy_philo_meals_ate(philos, num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_m_destroy_philo_last_meal(philos, num_philos);
	if (err != SUCCESS)
		return (err);
	return (SUCCESS);
}
