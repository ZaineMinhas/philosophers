/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:37:36 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/13 20:29:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*routine(void *philip)
{
	t_philo	*philo;

	philo = (t_philo *)philip;
	while (1)
	{
		take_forks(philo);
		eating(philo);
		sleeping(philo);
	}
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
