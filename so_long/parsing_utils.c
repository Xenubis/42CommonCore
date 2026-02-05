/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:22:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/02 14:27:15 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pos_player(t_game *para, int i, int j)
{
	para->player_count++;
	para->player_x = j;
	para->player_y = i;
}

static void	pos_monster(t_game *para, int i, int j)
{
	para->monster_x[para->monster_count] = j;
	para->monster_y[para->monster_count] = i;
	para->monster_count++;
}

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
			if (ft_strchr("01PECM", para->map[i][j]) == NULL)
				error_end("Error : map invalid\n", para);
			if (para->map[i][j] == 'P')
				pos_player(para, i, j);
			if (para->map[i][j] == 'E')
				para->exit_count++;
			if (para->map[i][j] == 'C')
				para->collectible_count++;
			if (para->map[i][j] == 'M')
				pos_monster(para, i, j);
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
			error_end("Error : map invalid\n", para);
		if (para->map[para->height - 1][i] != '1')
			error_end("Error : map invalid\n", para);
		i++;
	}
	i = 1;
	while (i <= (para->height - 2))
	{
		if (para->map[i][0] != '1')
			error_end("Error : map invalid\n", para);
		if (para->map[i][para->width - 1] != '1')
			error_end("Error : map invalid\n", para);
		i++;
	}
}

void	setup_bis(char *path, int i, t_game *para)
{
	if (i < 5)
		error_end("Usage : path/namemap.ber\n", para);
	if (ft_strncmp((path + i - 4), ".ber", 4) != 0)
		error_end("Usage : path/namemap.ber\n", para);
}
