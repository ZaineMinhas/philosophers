/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:54:48 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/13 20:22:28 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->talk_wand);
	printf("%llu %d %s\n", gettime() - philo->table->start, philo->id, str);
	pthread_mutex_unlock(&philo->table->talk_wand);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	print(philo, "is eating");
	usleep(philo->table->ti_eat * 1000);
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	usleep(philo->table->ti_slp * 1000);
	print(philo, "is thinking");
}
