/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:18:31 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/24 13:51:27 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[34;01m%ld ms Philosopher %d has taken left fork\033[00m\n",
		(get_time() - philo->data->starting_time),
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (is_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[34;01m%ld ms Philosopher %d has taken right fork\033[00m\n",
		(get_time() - philo->data->starting_time),
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_bite(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->bite_mutex);
	philo->last_bite = get_time();
	pthread_mutex_unlock(&philo->data->bite_mutex);
	if (is_dead(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[32;01m%ld ms Philosopher %d is eating\033[00m\n", (get_time()
			- philo->data->starting_time), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	ft_usleep(philo->data->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[33;01m%ld ms Philosopher %d is sleeping\033[00m\n", (get_time()
			- philo->data->starting_time), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	ft_usleep(philo->data->time_to_sleep);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
