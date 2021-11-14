/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:37:36 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/14 17:25:52 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*end_calc(void *philip)
{
	t_philo	*philo;
	int		count;
	int		i;

	philo = (t_philo *)philip;
	while (1)
	{
		if (gettime() >= \
		philo->table->ti_die + philo->last_eat && !philo->is_eating)
		{
			print(philo, "died");
			pthread_mutex_unlock(&philo->table->dead);
		}
		if (philo->table->nb_eat)
		{
			i = -1;
			count = 0;
			while (++i < philo->table->nb_phil)
				if (philo->table->philo[i].nbr_eat >= philo->table->nb_eat)
					count++;
			if (count == philo->table->nb_phil)
				pthread_mutex_unlock(&philo->table->dead);
		}
		usleep(100);
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
		take_forks(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

int	philo_life(t_table *table)
{
	pthread_t	philo;
	int			i;

	i = -1;
	table->start = gettime();
	while (++i < table->nb_phil)
	{
		if (pthread_create(&philo, NULL, &routine, (void *)(table->philo + i)))
			return (1);
		pthread_detach(philo);
		usleep(100);
	}
	return (0);
}
