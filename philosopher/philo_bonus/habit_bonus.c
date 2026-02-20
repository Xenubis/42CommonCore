/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habit_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:20:57 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/20 14:26:48 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	check_delay_time(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(philo->data->time_to_eat);
	}
	else
	{
		if (philo->id % 3 == 2)
			ft_usleep(philo->data->time_to_eat);
		else if (philo->id % 3 == 0)
			ft_usleep(philo->data->time_to_eat * 2);
	}
}

void	*grim_reaper(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->data->bite_mutex);
		if (get_time() - philo->last_bite > philo->data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->bite_mutex);
			sem_wait(philo->data->print);
			printf("%ld ms Philosopher %d is dead\n", (get_time()
					- philo->data->starting_time), philo->id);
			exit (1);
		}
		pthread_mutex_unlock(&philo->data->bite_mutex);
		ft_usleep(2);
	}
}

void	habit(t_philo *philo)
{
	pthread_mutex_init(&philo->data->bite_mutex, NULL);
	pthread_create(&philo->thread, NULL, grim_reaper, philo);
	pthread_detach(philo->thread);
	check_delay_time(philo);
	while (1)
	{
		sem_wait(philo->data->sit);
		take_fork(philo);
		take_fork(philo);
		take_bite(philo);
		put_down_fork(philo);
		sem_post(philo->data->sit);
		philo->nb_bite++;
		if (philo->nb_bite == philo->data->nb_bite_need)
			exit(0);
		sleeping(philo);
		think(philo);
	}
}
