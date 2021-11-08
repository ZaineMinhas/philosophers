/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/08 18:46:12 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	read_arg(t_var *var, int ac, char **av)
{
	int	i;

	var->nb_phil = ft_atoi(av[1]);
	var->ti_die = ft_atoi(av[2]);
	var->ti_eat = ft_atoi(av[3]);
	var->ti_slp = ft_atoi(av[4]);
	if (av[5])
		var->nb_eat = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac != 4 && ac != 5)
		return (1);
	read_arg(&var);
	return (0);
}
