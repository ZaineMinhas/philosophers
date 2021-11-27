/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:54:48 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/27 19:25:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print(t_philo *philo, int type, int end)
{
	if (philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->talk_staff);
	if (philo->table->is_dead)
		return ;
	if (end)
		philo->table->is_dead = 1;
	if (type == 1)
		write_thinking(philo);
	else if (type == 2)
		write_take_forks(philo);
	else if (type == 3)
		write_eating(philo);
	else if (type == 4)
		write_sleeping(philo);
	else if (type == 5)
		write_died(philo);
	if (end)
		return ;
	pthread_mutex_unlock(&philo->table->talk_staff);
}

void	take_forks(t_philo *philo)
{
	if (philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print(philo, 2, 0);
	if (philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print(philo, 2, 0);
	if (philo->table->is_dead)
		return ;
}

void	eating(t_philo *philo)
{
	if (philo->table->is_dead)
		return ;
	philo->is_eating = 1;
	philo->last_eat = gettime();
	wait_in_ms(philo->table->ti_eat);
	philo->is_eating = 0;
	philo->nbr_eat++;
	print(philo, 3, 0);
	if (philo->table->is_dead)
		return ;
}

void	sleeping(t_philo *philo)
{
	if (philo->table->is_dead)
		return ;
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
	print(philo, 4, 0);
	wait_in_ms(philo->table->ti_slp);
	if (philo->table->is_dead)
		return ;
}
