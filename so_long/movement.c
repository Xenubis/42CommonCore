/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:35:39 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 16:21:07 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *para)
{
	int new_y;

	if (para->win == 1)
		return ;
	para->win = 0;
	new_y = para->player_y - 1;
	if (para->map[new_y][para->player_x] == '1')
		return ;
	if (para->map[new_y][para->player_x] == 'C')
		para->collectible++;
	if (para->map[new_y][para->player_x] == 'E'
		&& para->collectible == para->collectible_count)
		para->win = 1;
	check_exit(para);
	if (para->map[new_y][para->player_x] == 'E')
		para->on_exit = 1;	
	para->map[new_y][para->player_x] = 'P';
	para->player_y = new_y;
	para->move++;
	display_map(para);
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
	display_move(para);
	if (para->win == 1)
		gg(para);
}

void	move_down(t_game *para)
{
	int new_y;

	if (para->win == 1)
		return ;
	para->win = 0;
	new_y = para->player_y + 1;
	if (para->map[new_y][para->player_x] == '1')
		return ;
	if (para->map[new_y][para->player_x] == 'C')
		para->collectible++;
	if (para->map[new_y][para->player_x] == 'E'
		&& para->collectible == para->collectible_count)
		para->win = 1;
	check_exit(para);
	if (para->map[new_y][para->player_x] == 'E')
		para->on_exit = 1;	
	para->map[new_y][para->player_x] = 'P';
	para->player_y = new_y;
	para->move++;
	display_map(para);
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
	display_move(para);
	if (para->win == 1)
		gg(para);
}

void	move_left(t_game *para)
{
	int new_x;

	if (para->win == 1)
		return ;
	para->win = 0;
	new_x = para->player_x - 1;
	if (para->map[para->player_y][new_x] == '1')
		return ;
	if (para->map[para->player_y][new_x] == 'C')
		para->collectible++;
	if (para->map[para->player_y][new_x] == 'E'
		&& para->collectible == para->collectible_count)
		para->win = 1;
	check_exit(para);
	if (para->map[para->player_y][new_x] == 'E')
		para->on_exit = 1;	
	para->map[para->player_y][new_x] = 'P';
	para->player_x = new_x;
	para->move++;
	display_map(para);
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
	display_move(para);
	if (para->win == 1)
		gg(para);
}

void	move_right(t_game *para)
{
	int new_x;

	if (para->win == 1)
		return ;
	para->win = 0;
	new_x = para->player_x + 1;
	if (para->map[para->player_y][new_x] == '1')
		return ;
	if (para->map[para->player_y][new_x] == 'C')
		para->collectible++;
	if (para->map[para->player_y][new_x] == 'E'
		&& para->collectible == para->collectible_count)
		para->win = 1;
	check_exit(para);
	if (para->map[para->player_y][new_x] == 'E')
		para->on_exit = 1;	
	para->map[para->player_y][new_x] = 'P';
	para->player_x = new_x;
	para->move++;
	display_map(para);
	ft_putnbr_fd(para->move, 1);
	write(1, "\n", 1);
	display_move(para);
	if (para->win == 1)
		gg(para);
}

void check_exit(t_game *para)
{
	if (para->on_exit == 1)
		para->map[para->player_y][para->player_x] = 'E';
	if (para->on_exit == 0)
		para->map[para->player_y][para->player_x] = '0';
	para->on_exit = 0;
}