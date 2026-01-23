/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:47 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 19:43:58 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_number(t_game *para)
{
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
}

void	check_exit(t_game *para)
{
	if (para->on_exit == 1)
		para->map[para->player_y][para->player_x] = 'E';
	if (para->on_exit == 0)
		para->map[para->player_y][para->player_x] = '0';
	para->on_exit = 0;
}
