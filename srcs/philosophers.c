/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/13 20:16:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

unsigned long long	gettime(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	return_error(char *str)
{
	if (str)
		printf("%s\n", str);
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 4 && ac != 5)
		return (return_error("Wrong arument !!!"));
	if (read_arg(&table, ac, av))
		return (return_error("Error"));
	if (philo_life(&table))
		return (return_error("Thread error"));
	pthread_mutex_lock(&table.dead);
	pthread_mutex_unlock(&table.dead);
	return (0);
}
