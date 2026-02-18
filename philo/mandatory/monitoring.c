/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:27:44 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/17 17:10:51 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	death(t_data *data, int j)
{
	pthread_mutex_lock(&data->dead_mutex);
	data->he_dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld ms Philosopher %d is dead\n", (get_time()
			- data->starting_time), data->philos[j].id);
	pthread_mutex_unlock(&data->print_mutex);
}

void	eye_of_sauron(t_data *data)
{
	int	j;
	int	done;

	while (1)
	{
		j = -1;
		done = 0;
		while (++j < data->nb_philo)
		{
			if (lock_nb_bite(&data->philos[j])
				== lock_nb_bite_need(data->philos)
				&& data->nb_bite_need != -1)
				done++;
			if (check_last_bite(data, j) > data->time_to_die
				&& lock_nb_bite(&data->philos[j])
				!= lock_nb_bite_need(data->philos))
			{
				death(data, j);
				return ;
			}
		}
		if (done == data->nb_philo)
			return ;
		ft_usleep(2);
	}
}
