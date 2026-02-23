/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:23 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/23 16:33:48 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	check_last_bite(t_data *data, int j)
{
	long	tmp;

	pthread_mutex_lock(&data->bite_mutex);
	tmp = get_time() - data->philos[j].last_bite;
	pthread_mutex_unlock(&data->bite_mutex);
	return (tmp);
}

int	is_dead(t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(&philo->data->dead_mutex);
	tmp = philo->data->he_dead;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (tmp);
}

int	lock_nb_bite_need(t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(&philo->data->bite_mutex);
	tmp = philo->data->nb_bite_need;
	pthread_mutex_unlock(&philo->data->bite_mutex);
	return (tmp);
}

int	lock_nb_bite(t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(&philo->data->bite_mutex);
	tmp = philo->nb_bite;
	pthread_mutex_unlock(&philo->data->bite_mutex);
	return (tmp);
}
