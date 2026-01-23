/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:22:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/22 16:36:06 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_carac(t_game *para)
{
	int	i;
	int	j;

	i = 0;
	while (para->map[i])
	{
		j = 0;
		while (para->map[i][j])
		{
			if (ft_strchr("01PEC", para->map[i][j]) == NULL)
				error_end("Error : map invalid\n", para);
			if (para->map[i][j] == 'P')
			{
				para->player_count++;
				para->player_x = j;
				para->player_y = i;
			}
			if (para->map[i][j] == 'E')
				para->exit_count++;
			if (para->map[i][j] == 'C')
				para->collectible_count++;
			j++;
		}
		i++;
	}
}

void	check_wall(t_game *para)
{
	int	i;

	i = 0;
	while (i < para->width)
	{
		if (para->map[0][i] != '1')
			error_end("Error : map invalide\n", para);
		if (para->map[para->height - 1][i] != '1')
			error_end("Error : map invalide\n", para);
		i++;
	}
	i = 1;
	while (i <= (para->height - 2))
	{
		if (para->map[i][0] != '1')
			error_end("Error : map invalide\n", para);
		if (para->map[i][para->width - 1] != '1')
			error_end("Error : map invalide\n", para);
		i++;
	}
}
