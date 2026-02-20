/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:11:04 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/20 15:10:01 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_usleep(long duration)
{
	long	time;

	time = get_time();
	while (get_time() - time < duration)
	{
		usleep(1);
	}
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec) * 1000) + ((tv.tv_usec) / 1000);
	return (time);
}
