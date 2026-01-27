/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:03:54 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/27 16:59:25 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy1(t_game *para)
{
	if (para->img_minish_down[0])
		mlx_destroy_image(para->mlx, para->img_minish_down[0]);
	if (para->img_minish_down[1])
		mlx_destroy_image(para->mlx, para->img_minish_down[1]);
	if (para->img_minish_down[2])
		mlx_destroy_image(para->mlx, para->img_minish_down[2]);
	if (para->img_minish_exit[0])
		mlx_destroy_image(para->mlx, para->img_minish_exit[0]);
	if (para->img_minish_exit[1])
		mlx_destroy_image(para->mlx, para->img_minish_exit[1]);
	if (para->img_minish_exit[2])
		mlx_destroy_image(para->mlx, para->img_minish_exit[2]);
	if (para->img_minish_up[0])
		mlx_destroy_image(para->mlx, para->img_minish_up[0]);
	if (para->img_minish_up[1])
		mlx_destroy_image(para->mlx, para->img_minish_up[1]);
	if (para->img_minish_up[2])
		mlx_destroy_image(para->mlx, para->img_minish_up[2]);
	if (para->img_minish_left[0])
		mlx_destroy_image(para->mlx, para->img_minish_left[0]);
	if (para->img_minish_left[1])
		mlx_destroy_image(para->mlx, para->img_minish_left[1]);
	if (para->img_minish_left[2])
		mlx_destroy_image(para->mlx, para->img_minish_left[2]);
}

void	destroy2(t_game *para)
{
	if (para->img_minish_right[0])
		mlx_destroy_image(para->mlx, para->img_minish_right[0]);
	if (para->img_minish_right[1])
		mlx_destroy_image(para->mlx, para->img_minish_right[1]);
	if (para->img_minish_right[2])
		mlx_destroy_image(para->mlx, para->img_minish_right[2]);
	if (para->img_monster[0])
		mlx_destroy_image(para->mlx, para->img_monster[0]);
	if (para->img_monster[1])
		mlx_destroy_image(para->mlx, para->img_monster[1]);
	if (para->img_monster[2])
		mlx_destroy_image(para->mlx, para->img_monster[2]);
	if (para->img_collectible[0])
		mlx_destroy_image(para->mlx, para->img_collectible[0]);
	if (para->img_collectible[1])
		mlx_destroy_image(para->mlx, para->img_collectible[1]);
	if (para->img_collectible[2])
		mlx_destroy_image(para->mlx, para->img_collectible[2]);
	if (para->img_collectible[3])
		mlx_destroy_image(para->mlx, para->img_collectible[3]);
}

void	destroy3(t_game *para)
{
	if (para->img_exit)
		mlx_destroy_image(para->mlx, para->img_exit);
	if (para->img_floor)
		mlx_destroy_image(para->mlx, para->img_floor);
	if (para->img_wall)
		mlx_destroy_image(para->mlx, para->img_wall);
}
