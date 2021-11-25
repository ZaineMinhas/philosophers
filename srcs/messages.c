/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:56:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/25 18:23:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	write_thinking(t_philo *philo)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr("\t\033[34m ");
	ft_putnbr(philo->id);
	ft_putstr(" is thinking\n\033[0m");
}

void	write_take_forks(t_philo *philo)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr("\t\033[35m ");
	ft_putnbr(philo->id);
	ft_putstr(" has taken a fork\n\033[0m");
}

void	write_eating(t_philo *philo)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr("\t\033[33m ");
	ft_putnbr(philo->id);
	ft_putstr(" is eating\n\033[0m");
}

void	write_sleeping(t_philo *philo)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr("\t\033[36m ");
	ft_putnbr(philo->id);
	ft_putstr(" is sleeping\n\033[0m");
}

void	write_died(t_philo *philo)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr("\t\033[31m ");
	ft_putnbr(philo->id);
	ft_putstr(" died\n\033[0m");
}
