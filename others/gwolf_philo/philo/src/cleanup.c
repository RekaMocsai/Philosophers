/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:29:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 15:31:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

/**
 * @brief Deallocate and destroy mutexes.
 *
 * Depending on the setup stage of the programm calls different fts.
 * POST_MUTEX_PHILO > ft_m_destroy_philo().
 * POST_MUTEX_FORK > ft_m_destroy_forks_in_use().
 * POST_MUTEX_DATA > destroy m_print mutex.
 * POST_MALLOC > free philos and forks.
 *
 * @param data Struct containing simulation data.
 * @param err Error Code
 * @param num_philos Number of philos.
 * @return t_err Received t_err or PANIC
 */
t_err	ft_cleanup(t_data *data, t_err err, int32_t num_philos)
{
	if (data->stage == POST_MUTEX_PHILO)
	{
		if (ft_m_destroy_philo(data->philos, num_philos) != SUCCESS)
			return (ft_print_err_msg(PANIC));
	}
	if (data->stage >= POST_MUTEX_FORK)
	{
		if (ft_m_destroy_forks_in_use(data->forks, num_philos) != SUCCESS)
			return (ft_print_err_msg(PANIC));
	}
	if (data->stage >= POST_MUTEX_DATA)
		if (pthread_mutex_destroy(&data->m_print) != 0)
			return (ft_print_err_msg(PANIC));
	if (data->stage >= POST_MALLOC)
	{
		free(data->philos);
		free(data->forks);
	}
	printf("🧹 All cleaned up.\n");
	return (ft_print_err_msg(err));
}
