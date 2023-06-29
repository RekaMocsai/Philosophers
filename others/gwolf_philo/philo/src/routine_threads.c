/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:36:04 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 16:08:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

/**
 * @brief Set start timer for simulation and philos
 *
 * @param philos Array of philos.
 * @param params Pointer to struct param.
 * @return t_err SUCCESS, ERR_TIME
 */
t_err	ft_set_startup_time(t_philo *philos, t_params *params)
{
	int32_t	i;

	params->start_time = ft_timestamp_in_ms();
	if (params->start_time == -1)
		return (ERR_TIME);
	i = 0;
	while (i < params->num_philos)
	{
		philos[i].last_meal = ft_timestamp_in_ms();
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Set time and create threads for all philos.
 *
 * ft_set_startup_time().
 * Creates a thread for every philo.
 * If it can't create all threads call ft_stop_and_join()
 * If all threads created it calls ft_monitoring().
 *
 * @param data Pointer to big data struct.
 * @param philos Array of philos.
 * @param params Pointer to struct params.
 * @return t_err SUCCESS, ERR_THREAD_CREATE
 */
t_err	ft_spin_threads(t_data *data, t_philo *philos, t_params *params)
{
	int32_t		i;

	ft_set_startup_time(philos, params);
	i = 0;
	while (i < params->num_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL,
				ft_philo_life, &philos[i]) != 0)
		{
			printf("🔥 Could not create philo thread with ID %d\n", i);
			return (ft_stop_and_join(data, i));
		}
		i++;
	}
	ft_monitoring(philos, data->meals);
	return (SUCCESS);
}

/**
 * @brief Join all philo threads.
 *
 * @param philos Array of philos.
 * @param params Struct params.
 * @return t_err SUCCESS
 */
t_err	ft_join_threads(t_philo *philos, t_params *params)
{
	int32_t	i;

	i = 0;
	while (i < params->num_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Set status of philos to DEAD and join all threads.
 *
 * If ft_spin_threads() fails this function sets all working philos
 * to DEAD. It then joins all the trheads to wait for them to exit.
 *
 * @param data Data struct.
 * @param num_philos Number of philos.
 * @return t_err ERR_THREAD_CREATE
 */
t_err	ft_stop_and_join(t_data *data, int32_t num_philos)
{
	ft_set_status_all(data->philos, DEAD);
	num_philos--;
	while (num_philos >= 0)
	{
		pthread_join(data->philos[num_philos].thread_id, NULL);
		num_philos--;
	}
	return (ERR_THREAD_CREATE);
}
