/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:54:04 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/27 14:01:25 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_create_caracter(t_game *para)
{
	int	img_w;
	int	img_h;

	para->img_minish_down[0] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_down.xpm", &img_w, &img_h);
	para->img_minish_down[1] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_down_left.xpm", &img_w, &img_h);
	para->img_minish_down[2] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_down_right.xpm", &img_w, &img_h);
	para->img_minish_exit[0] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_exit.xpm", &img_w, &img_h);
	para->img_minish_exit[1] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_exit_left.xpm", &img_w, &img_h);
	para->img_minish_exit[2] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_exit_right.xpm", &img_w, &img_h);
	para->img_monster[0] = mlx_xpm_file_to_image(para->mlx,
			"image/monster_mid.xpm", &img_w, &img_h);
	para->img_monster[1] = mlx_xpm_file_to_image(para->mlx,
			"image/monster_high.xpm", &img_w, &img_h);
	para->img_monster[2] = mlx_xpm_file_to_image(para->mlx,
			"image/monster_low.xpm", &img_w, &img_h);
}

void	mlx_create_caracter2(t_game *para)
{
	int	img_w;
	int	img_h;

	para->img_minish_left[0] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_left.xpm", &img_w, &img_h);
	para->img_minish_left[1] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_left_left.xpm", &img_w, &img_h);
	para->img_minish_left[2] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_left_right.xpm", &img_w, &img_h);
	para->img_minish_right[0] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_right.xpm", &img_w, &img_h);
	para->img_minish_right[1] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_right_left.xpm", &img_w, &img_h);
	para->img_minish_right[2] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_right_right.xpm", &img_w, &img_h);
	para->img_minish_up[0] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_up.xpm", &img_w, &img_h);
	para->img_minish_up[1] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_up_left.xpm", &img_w, &img_h);
	para->img_minish_up[2] = mlx_xpm_file_to_image(para->mlx,
			"image/minish_up_right.xpm", &img_w, &img_h);
}

void	mlx_create_add(t_game *para)
{
	int	img_w;
	int	img_h;

	para->img_collectible[0] = mlx_xpm_file_to_image(para->mlx,
			"image/collectible.xpm", &img_w, &img_h);
	para->img_collectible[2] = mlx_xpm_file_to_image(para->mlx,
			"image/collectible_right.xpm", &img_w, &img_h);
	para->img_collectible[1] = mlx_xpm_file_to_image(para->mlx,
			"image/collectible_left.xpm", &img_w, &img_h);
	para->img_collectible[3] = mlx_xpm_file_to_image(para->mlx,
			"image/collectible_right2.xpm", &img_w, &img_h);
	para->img_exit = mlx_xpm_file_to_image(para->mlx, "image/exit.xpm",
			&img_w, &img_h);
	para->img_floor = mlx_xpm_file_to_image(para->mlx, "image/floor.xpm",
			&img_w, &img_h);
	para->img_wall = mlx_xpm_file_to_image(para->mlx, "image/wall.xpm",
			&img_w, &img_h);
}

int	animation(t_game *para)
{
	struct timeval	tv;
	long			time;

	if (para->win == 1 || para->dead == 1)
		return (0);
	time = 0;
	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (time - para->last_frame > ANIMATION_SPEED)
	{
		para->current_frame++;
		para->last_frame = time;
	}
	move_monster(para);
	if (para->dead == 1)
	{
		display_map(para);
		you_died(para);
		return (0);
	}
	display_map(para);
	return (0);
}

void	move_number(t_game *para)
{
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
}
