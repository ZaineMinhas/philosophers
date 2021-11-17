/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/11/17 17:59:10 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	make_clean(t_table *table, int type)
{
	
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

	if (ac != 5 && ac != 6)
		return (return_error("Wrong arument !!!"));
	if (read_arg(&table, ac, av))
		return (return_error("Error"));
	if (philo_life(&table))
		return (return_error("Thread error"));
	pthread_mutex_lock(&table.dead);
	pthread_mutex_unlock(&table.dead);
	make_fclean(&table);
	return (0);
}
