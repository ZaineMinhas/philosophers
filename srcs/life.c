/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:37:36 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/18 19:14:02 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	end_meal(t_philo *philo)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (++i < philo->table->nb_phil)
		if (philo->table->philo[i].nbr_eat >= philo->table->nb_eat)
			count++;
	if (count == philo->table->nb_phil)
	{
		pthread_mutex_lock(&philo->table->talk_staff);
		pthread_mutex_unlock(&philo->table->dead);
		print(philo, "PONG LENIS", 1, 0);
		return ;
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
			print(philo, "died", 1, 1);
			pthread_mutex_unlock(&philo->table->dead);
			return (NULL);
		}
		if (philo->table->nb_eat)
			end_meal(philo);
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
	}
	return (0);
}
