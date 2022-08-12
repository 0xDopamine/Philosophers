/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:49:48 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/12 09:43:43 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

typedef enum {
	EAT,
	SLEEP,
	THINK,
	DIE,
	FORK
} state;


typedef struct s_data {
	int				argc;
	int				num_ph;
	int				time_eat;
	int				time_death;
	int				time_sleep;
	int				must_eat;
	int				total;
	pthread_mutex_t	message;
	int				index;
	int				stop;
} t_data ;

typedef struct s_philo {
	int				id;
	pthread_t		ph_id;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
	t_data			*data;
} t_philo ;

typedef struct s_ph {
	t_philo	*philo;
	t_data	data;
} t_ph ;

int			ft_isdigit(int c);
int			ft_check_argument(char *arg);
int			ft_atoi(const char *str);
void		ft_philosophers(t_ph *ph);
long int    actual_time(void);
void		ft_usleep(long int time_ms);
void		reset();
void		blue();
void		red();
void		purple();
void    	print_msg(int id, long int time, state x);
#endif