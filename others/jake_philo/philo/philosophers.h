/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:10:04 by jklocker          #+#    #+#             */
/*   Updated: 2022/12/13 13:42:51 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_arg_info	t_arg_info;

typedef struct s_phil
{
	pthread_t				thread;
	int						id;
	int						is_dead;
	int						times_eaten;
	int						done_eating;
	int						has_forks;
	struct timeval			time_till_death;
	int						*l_fork;
	int						*r_fork;
	t_arg_info				*info;
}							t_phil;

typedef struct s_arg_info
{
	pthread_mutex_t			*fork_mutex;
	pthread_mutex_t			print_mutex;
	int						phil_nbr;
	struct timeval			start_time;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						times_must_eaten;
	int						*forks;
	t_phil					*phil_ptr;
}							t_arg_info;

//eat sleep think
void						check_forks(t_phil *phil);
void						eat(t_phil *phil);
void						*eat_sleep_repeat(t_phil *phil);
void						check_phil_times(t_arg_info *info);

//argv_infos
int							get_arg_info(t_arg_info *info, int argc,
								char **argv);
int							modified_atoi(char *str);

//get_time
long						calc_timestamp(t_arg_info *info);
long						calc_if_dead(t_phil *phil);

//create threads
int							init_info_vars(t_arg_info *info);
int							create_threads(t_arg_info *info);
int							join_all(t_arg_info *info);

//error free
int							usage_message(t_arg_info *info);
int							error_occured(t_arg_info *info);
int							free_all(t_arg_info *info);

//Philos Checks
void						dead_or_all_eaten(t_arg_info *info);
int							philos_eaten(t_arg_info *info);
int							philos_alive(t_arg_info *info);

//Print msg
void						print_msgs(t_phil *phil, int index);

//Create Mutex
void						create_mutex(t_arg_info *info);
void						destroy_mutex(t_arg_info *info);

#endif