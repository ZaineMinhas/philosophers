/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:54:48 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/18 18:37:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print(t_philo *philo, char *str, int b1o, int b2o)
{
	unsigned long long	timestamp;
	static int			dead = 0;

	pthread_mutex_lock(&philo->table->talk_staff);
	if (!dead)
	{
		if (!b2o)
		{
			dead = 1;
			return ;
		}
		timestamp = gettime() - philo->table->start;
		printf("%llu %d %s\n", timestamp, philo->id, str);
		if (b1o)
		{
			dead = 1;
			return ;
		}
	}
	pthread_mutex_unlock(&philo->table->talk_staff);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print(philo, "has taken a fork", 0, 1);
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print(philo, "has taken a fork", 0, 1);
}

void	eating(t_philo *philo)
{
	philo->is_eating = 1;
	print(philo, "is eating", 0, 1);
	wait_in_ms(philo->table->ti_eat);
	philo->is_eating = 0;
	philo->nbr_eat++;
	philo->last_eat = gettime();
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping", 0, 1);
	wait_in_ms(philo->table->ti_slp);
	print(philo, "is thinking", 0, 1);
}
