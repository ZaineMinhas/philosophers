/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:23:37 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/27 19:24:56 by zminhas          ###   ########.fr       */
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
	t_table				*table;
	int					id;
	int					r_fork;
	int					l_fork;
	int					nbr_eat;
	int					is_eating;
	unsigned long long	last_eat;
}				t_philo;

struct s_table
{
	pthread_mutex_t		talk_staff;
	pthread_mutex_t		*forks;
	t_philo				*philo;
	unsigned long long	start;
	int					nb_phil;
	int					nb_eat;
	int					ti_die;
	int					ti_eat;
	int					ti_slp;
	int					is_dead;
};

int					read_arg(t_table *var, int ac, char **av);
void				init_philo(t_table *var);
int					init_mutex(t_table *var);
int					make_clean(t_table *table, int type);

int					philo_life(t_table *table);
void				*routine(void *philip);
void				take_forks(t_philo *philo);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);

void				print(t_philo *philo, int type, int end);
void				write_thinking(t_philo *philo);
void				write_take_forks(t_philo *philo);
void				write_eating(t_philo *philo);
void				write_sleeping(t_philo *philo);
void				write_died(t_philo *philo);

int					ft_error(char *str);
unsigned long long	gettime(void);
void				wait_in_ms(unsigned long long ms);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);

#endif