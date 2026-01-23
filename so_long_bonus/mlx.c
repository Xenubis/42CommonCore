/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:33 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 20:20:59 by mmusquer         ###   ########.fr       */
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
	mlx_create_caracter2(para);
	if (!(para->img_collectible) || !(para->img_exit) || !(para->img_floor)
		|| !(para->img_wall) || !(para->img_minish_down[0])
		|| !(para->img_minish_down[1]) || !(para->img_minish_down[2])
		|| !(para->img_minish_exit[0]) || !(para->img_minish_exit[1])
		|| !(para->img_minish_exit[2]) || !(para->img_minish_up[0])
		|| !(para->img_minish_up[1]) || !(para->img_minish_up[2])
		|| !(para->img_minish_left[0]) || !(para->img_minish_left[1])
		|| !(para->img_minish_left[2]) || !(para->img_minish_right[0])
		|| !(para->img_minish_right[1]) || !(para->img_minish_right[2]))
		error_end("Error : loading image\n", para);
}

void	display_map_exec(t_game *para, int x, int y)
{
	if (para->map[y][x] == '1')
		mlx_put_image_to_window(para->mlx, para->window, para->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == '0')
		mlx_put_image_to_window(para->mlx, para->window, para->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'P' && para->on_exit == 1)
		mlx_put_image_to_window(para->mlx, para->window,
			para->img_minish_exit[para->order[para->current_frame % 8]], x
			* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'E')
		mlx_put_image_to_window(para->mlx, para->window, para->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (para->map[y][x] == 'P')
		sprite_dir(para, x, y);
	else if (para->map[y][x] == 'C')
		mlx_put_image_to_window(para->mlx, para->window, para->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	sprite_dir(t_game *para, int x, int y)
{
	int		frame;
	void	*sprite;

	frame = para->order[para->current_frame % 8];
	if (para->player_dir == LOOK_DOWN)
		sprite = para->img_minish_down[frame];
	else if (para->player_dir == LOOK_UP)
		sprite = para->img_minish_up[frame];
	else if (para->player_dir == LOOK_LEFT)
		sprite = para->img_minish_left[frame];
	else
		sprite = para->img_minish_right[frame];
	mlx_put_image_to_window(para->mlx, para->window, sprite, x * TILE_SIZE, y
		* TILE_SIZE);
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
			display_move(para);
			x++;
		}
		y++;
	}
}
