/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:33 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 16:21:47 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_mlx(t_game *para)
{
	para->mlx = mlx_init();
	if (para->mlx == NULL)
		error_end("Error : mlx not found\n", para);
	para->window = mlx_new_window(para->mlx, para->width * TILE_SIZE,
			para->height * TILE_SIZE, "So_Long");
	if (!(para->window))
		error_end("Error : loading window\n", para);
	mlx_create_img(para);
	display_map(para);
}

void	mlx_create_img(t_game *para)
{
	mlx_create_add(para);
	mlx_create_caracter(para);
	if (!(para->img_collectible) || !(para->img_exit) || !(para->img_floor)
		|| !(para->img_wall) || !(para->img_minish_down)
		|| !(para->img_minish_left) || !(para->img_minish_right)
		|| !(para->img_minish_up))
		error_end("Error : loading image\n", para);
}

static void	display_map_exec(t_game *para, int x, int y)
{
	if (para->map[y][x] == '1')
		mlx_put_image_to_window(para->mlx, para->window, para->img_wall, x
				* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == '0')
		mlx_put_image_to_window(para->mlx, para->window, para->img_floor, x
				* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'P' && para->on_exit == 1)
		mlx_put_image_to_window(para->mlx, para->window, para->img_minish_exit, x
				* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'E')
		mlx_put_image_to_window(para->mlx, para->window, para->img_exit, x
				* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'P')
		mlx_put_image_to_window(para->mlx, para->window, para->img_minish_down,
				x * TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'C')
		mlx_put_image_to_window(para->mlx, para->window, para->img_collectible,
				x * TILE_SIZE, y * TILE_SIZE);
}

void	display_map(t_game *para)
{
	int	x;
	int	y;

	y = 0;
	while (para->map[y])
	{
		x = 0;
		while (para->map[y][x])
		{
			display_map_exec(para, x, y);
			x++;
		}
		y++;
	}
}

int	end_game(t_game *para)
{
	mlx_destroy_image(para->mlx, para->img_wall);
	mlx_destroy_image(para->mlx, para->img_collectible);
	mlx_destroy_image(para->mlx, para->img_exit);
	mlx_destroy_image(para->mlx, para->img_floor);
	mlx_destroy_image(para->mlx, para->img_minish_down);
	mlx_destroy_image(para->mlx, para->img_minish_left);
	mlx_destroy_image(para->mlx, para->img_minish_right);
	mlx_destroy_image(para->mlx, para->img_minish_up);
	mlx_destroy_window(para->mlx, para->window);
	free_tab(para->map);
	mlx_destroy_display(para->mlx);
	free(para->mlx);
	exit(0);
	return (0);
}