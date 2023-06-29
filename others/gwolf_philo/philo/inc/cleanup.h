/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:46:37 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 15:58:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <stdlib.h>

# include "philo_struct.h"
# include "return_codes.h"

//cleanup.c
t_err	ft_cleanup(t_data *data, t_err err, int32_t num_philos);

//cleanup_mutex.c
t_err	ft_m_destroy_forks_in_use(t_fork *forks, int32_t num_philos);
t_err	ft_m_destroy_philo_last_meal(t_philo *philos, int32_t num_philos);
t_err	ft_m_destroy_philo_meals_ate(t_philo *philos, int32_t num_philos);
t_err	ft_m_destroy_philo_status(t_philo *philos, int32_t num_philos);
t_err	ft_m_destroy_philo(t_philo *philos, int32_t num_philos);

#endif