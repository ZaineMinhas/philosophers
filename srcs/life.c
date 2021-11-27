/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:37:36 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/27 19:20:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*end_meal(void *p)
{
	t_table	*table;
	int		count;
	int		i;

	table = (t_table *)p;
	while (1)
	{
		i = -1;
		count = 0;
		while (++i < table->nb_phil)
			if (table->philo[i].nbr_eat >= table->nb_eat)
				count++;
		if (count == table->nb_phil)
		{
			pthread_mutex_lock(&table->talk_staff);
			table->is_dead = 1;
			return (NULL);
		}
	}
}

void	*end_calc(void *philip)
{
	t_philo	*philo;

	philo = (t_philo *)philip;
	while (1)
	{
		if (gettime() > \
		philo->table->ti_die + philo->last_eat && !philo->is_eating)
		{
			print(philo, 5, 1);
			philo->table->is_dead = 1;
			return (NULL);
		}
		wait_in_ms(1);
	}
}

void	*routine(void *philip)
{
	pthread_t	die;
	t_philo		*philo;

	philo = (t_philo *)philip;
	philo->last_eat = philo->table->start;
	if (pthread_create(&die, NULL, &end_calc, (void *)(philo)))
		return (NULL);
	while (1)
	{
		if (philo->table->is_dead)
			return (NULL);
		take_forks(philo);
		if (philo->table->is_dead)
			return (NULL);
		eating(philo);
		if (philo->table->is_dead)
			return (NULL);
		sleeping(philo);
		if (philo->table->is_dead)
			return (NULL);
		print(philo, 1, 0);
	}
	return (NULL);
}

int	philo_life(t_table *table)
{
	pthread_t	philo;
	int			i;

	i = -1;
	table->start = gettime();
	if (table->nb_eat)
		if (pthread_create(&philo, NULL, &end_meal, (void *)table))
			return (1);
	while (++i < table->nb_phil)
	{
		if (table->is_dead)
			return (0);
		if (pthread_create(&philo, NULL, &routine, (void *)(table->philo + i)))
			return (1);
		pthread_detach(philo);
		usleep(100);
	}
	return (0);
}
