/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:44:59 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/17 12:18:58 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static long	atoi_safe2(const char *str, int *error, int i, long res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
		{
			*error = 1;
			return (1);
		}
		i++;
	}
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != ' ')
		{
			*error = 1;
			return (1);
		}
		i++;
	}
	return (res);
}

int	atoi_safe(const char *str, int *error)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*error = 1;
		return (1);
	}
	if (!str[i])
	{
		*error = 1;
		return (1);
	}
	res = atoi_safe2(str, error, i, res);
	return (res);
}

void	parsing(int ac, char **av, t_data *data)
{
	int	error;

	error = 0;
	if (ac < 5 || ac > 6)
		error_end("Error : number of arguments\n");
	memset(data, 0, (sizeof(t_data)));
	data->nb_bite_need = -1;
	data->nb_philo = atoi_safe(av[1], &error);
	data->time_to_die = atoi_safe(av[2], &error);
	data->time_to_eat = atoi_safe(av[3], &error);
	data->time_to_sleep = atoi_safe(av[4], &error);
	if (ac == 6)
		data->nb_bite_need = atoi_safe(av[5], &error);
	if (error || data->nb_philo == 0)
		error_end("Error : argument format\n");
}
