/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:17:28 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/20 14:19:22 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
	{
		destroy_semaphore(data);
		error_end("Error : init semaphore");
	}
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_bite = data->starting_time;
		data->philos[i].nb_bite = 0;
		data->philos[i].data = data;
		i++;
	}
}

void	init_semaphore(t_data *data)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/sit");
	data->fork = sem_open("/fork", O_CREAT, 0644, data->nb_philo);
	if (data->fork == SEM_FAILED)
		error_end("Error : semaphore init\n");
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->print == SEM_FAILED)
		error_end("Error : semaphore init\n");
	data->sit = sem_open("/sit", O_CREAT, 0644, data->nb_philo - 1);
	if (data->sit == SEM_FAILED)
		error_end("Error : semaphore init\n");
}
