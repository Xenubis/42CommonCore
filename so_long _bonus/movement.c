/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:35:39 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/26 18:59:55 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	finish_move(t_game *para)
{
	display_map(para);
	move_number(para);
	if (para->win == 1)
		gg(para);
}

void	move_up(t_game *para)
{
	int	new_y;

	para->player_dir = LOOK_UP;
	if ((para->win == 1) || (para->dead == 1))
		return ;
	para->win = 0;
	new_y = para->player_y - 1;
	if (para->map[new_y][para->player_x] == '1')
		return ;
	monster_check(para, new_y, para->player_x);
	if (para->dead == 1)
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
	finish_move(para);
}

void	move_down(t_game *para)
{
	int	new_y;	

	para->player_dir = LOOK_DOWN;
	if ((para->win == 1) || (para->dead == 1))
		return ;
	para->win = 0;
	new_y = para->player_y + 1;
	if (para->map[new_y][para->player_x] == '1')
		return ;
	monster_check(para, new_y, para->player_x);
	if (para->dead == 1)
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
	finish_move(para);
}

void	move_left(t_game *para)
{
	int	new_x;

	para->player_dir = LOOK_LEFT;
	if ((para->win == 1) || (para->dead == 1))
		return ;
	para->win = 0;
	new_x = para->player_x - 1;
	if (para->map[para->player_y][new_x] == '1')
		return ;
	monster_check(para, para->player_y, new_x);
	if (para->dead == 1)
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
	finish_move(para);
}

void	move_right(t_game *para)
{
	int	new_x;

	para->player_dir = LOOK_RIGHT;
	if ((para->win == 1) || (para->dead == 1))
		return ;
	para->win = 0;
	new_x = para->player_x + 1;
	if (para->map[para->player_y][new_x] == '1')
		return ;
	monster_check(para, para->player_y, new_x);
	if (para->dead == 1)
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
	finish_move(para);
}
