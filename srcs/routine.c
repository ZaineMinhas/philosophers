/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:54:48 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/22 18:06:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print(t_philo *philo, int type, int end)
{
	static int			dead = 0;

	pthread_mutex_lock(&philo->table->talk_staff);
	if (dead)
		return ;
	if (end)
		dead = 1;
	if (type == 1)
		write_msg(philo, "is thinking\n", GREEN);
	else if (type == 2)
		write_msg(philo, "has taken a fork\n", PURPLE);
	else if (type == 3)
		write_msg(philo, "is eating\n", YELLOW);
	else if (type == 4)
		write_msg(philo, "is sleeping\n", CYAN);
	else if (type == 5)
		write_msg(philo, "died\n", RED);
	if (end)
		return ;
	pthread_mutex_unlock(&philo->table->talk_staff);
		//printf("%llu %s%d %s%s", timestamp, GREEN, philo->id, "is thinking\n", NC);
		//printf("%llu %s%d %s%s", timestamp, PURPLE, philo->id, "has taken a fork\n", NC);
		//printf("%llu %s%d %s%s", timestamp, YELLOW, philo->id, "is eating\n", NC);
		//printf("%llu %s%d %s%s", timestamp, CYAN, philo->id, "is sleeping\n", NC);
		//printf("%llu %s%d %s%s", timestamp, RED, philo->id, "died\n", NC);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print(philo, 2, 0);
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print(philo, 2, 0);
}

void	eating(t_philo *philo)
{
	philo->is_eating = 1;
	print(philo, 3, 0);
	wait_in_ms(philo->table->ti_eat);
	philo->is_eating = 0;
	philo->nbr_eat++;
	philo->last_eat = gettime();
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
}

void	sleeping(t_philo *philo)
{
	print(philo, 4, 0);
	wait_in_ms(philo->table->ti_slp);
	print(philo, 1, 0);
}
