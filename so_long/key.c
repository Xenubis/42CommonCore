/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:04:45 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/27 13:44:10 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *para)
{
	if (keycode == 65307)
	{
		write(1, "Thank you for playing\n", 22);
		end_game(para);
	}
	if (keycode == 119 || keycode == 65362)
		move_up(para);
	if (keycode == 115 || keycode == 65364)
		move_down(para);
	if (keycode == 97 || keycode == 65361)
		move_left(para);
	if (keycode == 100 || keycode == 65363)
		move_right(para);
	return (0);
}
