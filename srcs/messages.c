/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:56:03 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/22 18:01:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	write_msg(t_philo *philo, char *msg, char *color)
{
	ft_putnbr(gettime() - philo->table->start);
	ft_putstr(color);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	write(1, " ", 1);
	ft_putstr(msg);
	ft_putstr(NC);
}
