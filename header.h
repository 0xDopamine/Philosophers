/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:49:48 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/08/18 20:06:25 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

enum {
	DEAD,
	ALIVE,
	STOP,
	GO
} ;

typedef enum s_state {
	EAT,
	SLEEP,
	THINK,
	DIE,
	FORK
}	t_state;

typedef struct s_data {
	int				id;
	int				id_2;
	int				num_ph;
	int				time_eat;
	int				time_death;
	int				time_sleep;
	int				must_eat;
	int				total;
	long int		start_time;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	message;
	pthread_mutex_t sup_id;
	int				index;
	int				stop;
}	t_data;

typedef struct s_philo {
	int				id;
	pthread_t		ph_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	l_m_mutex;
	t_data			*data;
	int				meals;
	long int		last_meal;
}	t_philo;

typedef struct s_ph {
	t_philo		*philo;
	t_data		data;
}	t_ph;

int			ft_isdigit(char *str);
int			ft_check_argument(char **arg);
int			ft_atoi(const char *str);
void		ft_philosophers(t_ph *ph);
long int	actual_time(void);
void		ft_usleep(long int time_ms);
void		reset(void);
void		blue(void);
void		red(void);
void		purple(void);
void		print_msg(int id, long int time, t_state x);
void		ft_supervisor(t_ph *ph);
int			check_death(t_ph *ph);
void		ft_forks(t_ph *ph, int id, int id_2);
void		ft_eat(t_ph *ph, int id);
void		ft_sleep(t_ph *ph, int id);
void		ft_unlock_forks(t_ph *ph, int id, int id_2);
void		ft_think(t_ph *ph, int id);
void		ft_exit(void);
int			ft_atoi_tester(const char *str);
long		calres_tester(const char *str, int i, int sign);
int			check_eating(t_ph* ph);
#endif