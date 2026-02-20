/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:44:50 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/20 14:38:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	anakin_the_return(t_data *data, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
	i = 0;
	while (i < j)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
	destroy_semaphore(data);
	free(data->philos);
}

static void	forking(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == -1)
		{	
			anakin_the_return(data, i);
			error_end("Error : fork");
		}
		if (data->philos[i].pid == 0)
		{
			habit(&data->philos[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

static void	anakin(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
	destroy_semaphore(data);
	free(data->philos);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		status;

	parsing(ac, av, &data);
	init_semaphore(&data);
	data.starting_time = get_time();
	init_philo(&data);
	forking(&data);
	i = 0;
	while (i < data.nb_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 0)
			data.nb_finish_pid++;
		if (data.nb_finish_pid == data.nb_philo)
			break ;
		if (WEXITSTATUS(status) == 1)
			anakin(&data);
		i++;
	}
	destroy_semaphore(&data);
	free(data.philos);
	exit(EXIT_SUCCESS);
}
