/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/23 18:52:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait_in_ms(unsigned long long ms)
{
	unsigned long long	start;
	unsigned long long	end;

	start = gettime();
	end = start;
	while (end - start < ms)
	{
		usleep(100);
		end = gettime();
	}
}

int	make_clean(t_table *table, int type)
{
	int	i;

	if (type == 1)
		return (1);
	else if (type == 2)
		free(table->philo);
	else if (type == 3)
		free(table->forks);
	else if (type == 4)
	{
		i = -1;
		while (++i < table->nb_phil)
			pthread_mutex_destroy(&table->forks[i]);
	}
	else if (type == 5)
		pthread_mutex_destroy(&table->talk_staff);
	make_clean(table, --type);
	return (1);
}

int	return_error(char *str)
{
	if (str)
		printf("%s\n", str);
	return (1);
}

void	death_gate(t_table *table)
{
	while (!table->is_dead)
		;
	table->stop = 1;
	return ;
}

int	main(int ac, char **av)
{
	t_table	table;
	int		error;

	if (ac != 5 && ac != 6)
		return (return_error("Wrong arument !!!"));
	error = read_arg(&table, ac, av);
	if (error)
		return (return_error("Error") && make_clean(&table, error));
	if (philo_life(&table))
		return (return_error("Thread error") && make_clean(&table, 6));
	death_gate(&table);
	wait_in_ms(250);
	make_clean(&table, 5);
	return (0);
}
