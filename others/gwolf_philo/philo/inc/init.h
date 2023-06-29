/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:23:41 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 10:41:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "stdlib.h"
# include <string.h>

# include "philo_struct.h"
# include "return_codes.h"
# include "cleanup.h"

//init.c
t_err	ft_malloc_arrays(t_philo **philos, t_fork **forks, int32_t num_philos);
t_err	ft_init_philos(t_philo *philos, t_data *data, t_params *params);
t_err	ft_setup_vars(t_data *data, t_params *params);

//init_mutex.c
t_err	ft_m_init_forks_in_use(t_fork *forks, int32_t num_philos);
t_err	ft_m_init_philos_last_meal(t_philo *philos, int32_t num_philos);
t_err	ft_m_init_philos_status(t_philo *philos, int32_t num_philos);
t_err	ft_m_init_philos(t_philo *philos, int32_t num_philos);

#endif