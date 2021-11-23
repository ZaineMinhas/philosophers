/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:56:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/23 18:07:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	write_msg(t_philo *philo, char *msg, char *color)
{
	if (philo->table->stop)
		return ;
	ft_putnbr(gettime() - philo->table->start);
	write(1, "\t", 1);
	ft_putstr(color);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	write(1, " ", 1);
	ft_putstr(msg);
	ft_putstr(NC);
}

void	print(t_philo *philo, int type, int end)
{
	if (philo->table->stop || philo->table->is_dead)
		return ;
	pthread_mutex_lock(&philo->table->talk_staff);
	if (philo->table->is_dead)
		return ;
	if (end)
		philo->table->is_dead = 1;
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
}
