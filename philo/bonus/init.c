/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:17:28 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/16 18:02:58 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
	{
		destroy_mutex(data);
		error_end("Error : init mutex");
	}
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_bite = data->starting_time;
		data->philos[i].nb_bite = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->fork[i];
		data->philos[i].right_fork = &data->fork[(i + 1) % data->nb_philo];
		i++;
	}
}

void	init_mutex(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		error_end("Error : malloc mutex\n");
	while (i < data->nb_philo)
	{
		ret = pthread_mutex_init(&data->fork[i], NULL);
		if (ret != 0)
		{
			destroy_mutex(data);
			error_end("Error : init mutex");
		}
		i++;
	}
	ret = pthread_mutex_init(&data->bite_mutex, NULL);
	ret |= pthread_mutex_init(&data->dead_mutex, NULL);
	ret |= pthread_mutex_init(&data->print_mutex, NULL);
	if (ret != 0)
	{
		destroy_mutex(data);
		error_end("Error : init mutex");
	}
}
