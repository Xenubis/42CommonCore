/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:20:57 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:53 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	fork_habit(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
}

static void	do_habit(t_philo *philo)
{
	take_bite(philo);
	put_down_fork(philo);
	pthread_mutex_lock(&philo->data->bite_mutex);
	philo->nb_bite++;
	pthread_mutex_unlock(&philo->data->bite_mutex);
	sleeping(philo);
}

static int	lonely(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("\033[34;01m%ld ms Philosopher %d has taken left fork\033[00m\n", (get_time()
				- philo->data->starting_time), philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

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

void	*habit(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (lonely(philo) == 1)
		return (NULL);
	check_delay_time(philo);
	while (lock_nb_bite(philo) != lock_nb_bite_need(philo) && !is_dead(philo))
	{
		fork_habit(philo);
		if (is_dead(philo) == 1)
		{
			put_down_fork(philo);
			return (NULL);
		}
		do_habit(philo);
		think(philo);
	}
	return (NULL);
}
