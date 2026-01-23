/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:54:04 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 16:26:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_create_caracter(t_game *para)
{
	int	img_w;
	int	img_h;

	para->img_minish_down = mlx_xpm_file_to_image(para->mlx,
			"image/minish_down.xpm", &img_w, &img_h);
	para->img_minish_left = mlx_xpm_file_to_image(para->mlx,
			"image/minish_left.xpm", &img_w, &img_h);
	para->img_minish_right = mlx_xpm_file_to_image(para->mlx,
			"image/minish_right.xpm", &img_w, &img_h);
	para->img_minish_up = mlx_xpm_file_to_image(para->mlx,
			"image/minish_up.xpm", &img_w, &img_h);
	para->img_minish_exit = mlx_xpm_file_to_image(para->mlx,
			"image/minish_exit.xpm", &img_w, &img_h);
}
void	mlx_create_add(t_game *para)
{
	int	img_w;
	int	img_h;
	
	para->img_collectible = mlx_xpm_file_to_image(para->mlx,
			"image/collectible.xpm", &img_w, &img_h);
	para->img_exit = mlx_xpm_file_to_image(para->mlx, "image/exit.xpm",
			&img_w, &img_h);
	para->img_floor = mlx_xpm_file_to_image(para->mlx, "image/floor.xpm",
			&img_w, &img_h);
	para->img_wall = mlx_xpm_file_to_image(para->mlx, "image/wall.xpm",
			&img_w, &img_h);
}