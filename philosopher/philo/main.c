/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:44:50 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/19 17:56:23 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	parsing(ac, av, &data);
	init_mutex(&data);
	data.starting_time = get_time();
	init_philo(&data);
	while (i < data.nb_philo)
	{
		pthread_create(&data.philos[i].thread, NULL, habit, &data.philos[i]);
		i++;
	}
	eye_of_sauron(&data);
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	destroy_mutex(&data);
	free(data.philos);
	exit(EXIT_SUCCESS);
}
