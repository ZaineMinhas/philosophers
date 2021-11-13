/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:50:58 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/13 20:30:15 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_mutex(t_table *table)
{
	int	i;

	table->forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->nb_phil);
	if (!table->forks)
		return (1);
	i = -1;
	while (++i < table->nb_phil)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->talk_wand, NULL);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_lock(&table->dead);
	return (0);
}

void	init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_phil)
	{
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
		table->nb_eat = ft_atoi(av[5]);
	else
		table->nb_eat = 0;
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_phil);
	if (!table->philo)
		return (1);
	init_philo(table);
	return (init_mutex(table));
}
