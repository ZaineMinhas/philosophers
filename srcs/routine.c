/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:54:48 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/24 17:08:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
	print(philo, 3, 0);
	philo->last_eat = gettime();
	wait_in_ms(philo->table->ti_eat);
	philo->is_eating = 0;
	philo->nbr_eat++;
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
	if (philo->table->is_dead)
		return ;
}

void	sleeping(t_philo *philo)
{
	if (philo->table->is_dead)
		return ;
	print(philo, 4, 0);
	wait_in_ms(philo->table->ti_slp);
	print(philo, 1, 0);
	if (philo->table->is_dead)
		return ;
}
