/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:14:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 14:10:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_CODES_H
# define RETURN_CODES_H

# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

# define MSG_SUCCESS "👋 Goodbye!"
# define MSG_UNDEFINED "Something went wrong.\n"
# define MSG_NUMARGS "Wrong number of arguments.\n"
# define MSG_NOTDIGIT "Only positive digits as input are allowed.\n"
# define MSG_EMPTY_STR "There was an empty string.\n"
# define MSG_OVERFLOW "Args have to be <= INT_MAX.\n"
# define MSG_ISZERO "First arg [and/or optional last] has to be > 0.\n"
# define MSG_TIME "Function gettimeofday() failed.\n"
# define MSG_MALLOC "Function malloc() failed.\n"
# define MSG_MUTEX_INIT "Initialisation of mutex failed.\n"
# define MSG_MUTEX_DESTROY "Destruction of mutex failed.\n"
# define MSG_THREAD_CREATE "pthread_create() failed.\n"
# define MSG_PANIC "PANIC! Something went wrong during cleanup!\n"

typedef enum e_err {
	SUCCESS,
	STOP,
	ERR_UNDEFINED,
	ERR_NUMARGS,
	ERR_NOTDIGIT,
	ERR_EMPTY_STR,
	ERR_OVERFLOW,
	ERR_ISZERO,
	ERR_TIME,
	ERR_MALLOC,
	ERR_MUTEX_INIT,
	ERR_MUTEX_DESTROY,
	ERR_THREAD_CREATE,
	PANIC
}	t_err;

t_err	ft_print_usage(t_err err);
t_err	ft_print_err_msg(t_err err);

#endif