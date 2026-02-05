/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:34:50 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/27 13:50:25 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gg(t_game *para)
{
	int	x;
	int	y;

	x = (para->width * TILE_SIZE) / 2;
	y = (para->height * TILE_SIZE) / 2;
	mlx_string_put(para->mlx, para->window, x, y, 0xFFD700, "GG WP!");
	mlx_do_sync(para->mlx);
}

int	display_move(t_game *para)
{
	int		x;
	int		y;
	char	*move;

	move = ft_itoa(para->move);
	x = 10;
	y = 20;
	mlx_string_put(para->mlx, para->window, x, y, 0xFFFFFF, move);
	free(move);
	return (0);
}

void	you_died(t_game *para)
{
	int	x;
	int	y;

	x = (para->width * TILE_SIZE) / 2;
	y = (para->height * TILE_SIZE) / 2;
	mlx_string_put(para->mlx, para->window, x, y, 0xAD1328, "YOU DIED");
	mlx_do_sync(para->mlx);
}
