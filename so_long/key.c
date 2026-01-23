/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:04:45 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 11:47:47 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *para)
{
	if (keycode == 65307)
		error_end("Thank you for playing\n", para);
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