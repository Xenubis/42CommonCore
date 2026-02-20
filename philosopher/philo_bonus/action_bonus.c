/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:18:31 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/20 14:20:08 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->data->fork);
	sem_wait(philo->data->print);
	printf("%ld ms Philosopher %d has taken a fork\n", (get_time()
			- philo->data->starting_time), philo->id);
	sem_post(philo->data->print);
}

void	take_bite(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->bite_mutex);
	philo->last_bite = get_time();
	pthread_mutex_unlock(&philo->data->bite_mutex);
	sem_wait(philo->data->print);
	printf("%ld ms Philosopher %d is eating\n", (get_time()
			- philo->data->starting_time), philo->id);
	sem_post(philo->data->print);
	ft_usleep(philo->data->time_to_eat);
}

void	put_down_fork(t_philo *philo)
{
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->data->print);
	printf("%ld ms Philosopher %d is sleeping\n", (get_time()
			- philo->data->starting_time), philo->id);
	sem_post(philo->data->print);
	ft_usleep(philo->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	int	time_to_think;

	sem_wait(philo->data->print);
	printf("%ld ms Philosopher %d is thinking\n", (get_time()
			- philo->data->starting_time), philo->id);
	sem_post(philo->data->print);
	if (philo->data->nb_philo % 2 == 0)
		time_to_think = philo->data->time_to_eat - philo->data->time_to_sleep;
	else
		time_to_think = (philo->data->time_to_eat * 2)
			- philo->data->time_to_sleep;
	if (time_to_think > 0)
		ft_usleep(time_to_think);
}
