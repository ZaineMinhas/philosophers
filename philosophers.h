/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:23:37 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/13 20:26:12 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	t_table	*table;
	int		id;
	int		r_fork;
	int		l_fork;
}				t_philo;

struct s_table
{
	pthread_mutex_t		talk_wand;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead;
	t_philo				*philo;
	unsigned long long	start;
	int					nb_phil;
	int					nb_eat;
	int					ti_die;
	int					ti_eat;
	int					ti_slp;
};

int					read_arg(t_table *var, int ac, char **av);
void				init_philo(t_table *var);
int					init_mutex(t_table *var);

int					philo_life(t_table *table);
void				*routine(void *philip);
void				print(t_philo *philo, char *str);
void				take_forks(t_philo *philo);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);

unsigned long long	gettime(void);
int					return_error(char *str);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);

#endif