/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:20:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 14:40:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"

t_err	ft_counts_args(int argc);
t_err	ft_check_args(int argc, char **argv);
t_err	ft_set_params(t_params *params, int argc, char **argv, bool *meals);

#endif