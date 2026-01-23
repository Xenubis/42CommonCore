/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:55:12 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/22 17:26:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map_cpy, int height)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (height + 1));
	if (!tmp)
		return (NULL);
	while (i < height)
	{
		tmp[i] = ft_strdup(map_cpy[i]);
		if (!tmp[i])
			return (NULL);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void	flood_fill_exec(char **map_cpy, int x, int y, t_game *para)
{
	if (x < 0 || x >= para->width)
		return ;
	if (y < 0 || y >= para->height)
		return ;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'V')
		return ;
	map_cpy[y][x] = 'V';
	flood_fill_exec(map_cpy, x + 1, y, para);
	flood_fill_exec(map_cpy, x - 1, y, para);
	flood_fill_exec(map_cpy, x, y + 1, para);
	flood_fill_exec(map_cpy, x, y - 1, para);
}

static int	valid_map(char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'C' || map_cpy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_game *para)
{
	char	**map_cpy;

	map_cpy = copy_map(para->map, para->height);
	if (!map_cpy)
		return ;
	flood_fill_exec(map_cpy, para->player_x, para->player_y, para);
	if (!(valid_map(map_cpy)))
	{
		free_tab(map_cpy);
		error_end("Error : map invalid\n", para);
	}
	free_tab(map_cpy);
}
