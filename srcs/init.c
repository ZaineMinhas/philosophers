/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:50:58 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/27 16:54:22 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_error(char *str)
{
	if (str)
		printf("%s\n", str);
	return (1);
}

int	init_mutex(t_table *table)
{
	int	i;

	table->forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->nb_phil);
	if (!table->forks)
		return (2);
	i = -1;
	while (++i < table->nb_phil)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			while (i--)
				pthread_mutex_destroy(&table->forks[i]);
			return (3);
		}
	}
	if (pthread_mutex_init(&table->talk_staff, NULL))
		return (4);
	return (0);
}

void	init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_phil)
	{
		table->philo[i].nbr_eat = 0;
		table->philo[i].is_eating = 0;
		table->philo[i].id = i + 1;
		table->philo[i].l_fork = i;
		table->philo[i].r_fork = (i + 1) % table->nb_phil;
		table->philo[i].table = table;
	}
}

int	read_arg(t_table *table, int ac, char **av)
{
	table->nb_phil = ft_atoi(av[1]);
	table->ti_die = ft_atoi(av[2]);
	table->ti_eat = ft_atoi(av[3]);
	table->ti_slp = ft_atoi(av[4]);
	if (ac == 6)
	{
		table->nb_eat = ft_atoi(av[5]);
		if (!table->nb_eat)
			return (1);
	}
	else
		table->nb_eat = 0;
	table->is_dead = 0;
	if (table->nb_phil <= 0 || table->nb_phil > 200 || table->ti_die < 60 || \
		table->ti_eat < 60 || table->ti_slp < 60 || table->nb_eat < 0)
		return (ft_error("Error"));
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_phil);
	if (!table->philo)
		return (ft_error("Error"));
	init_philo(table);
	return (init_mutex(table));
}
