/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:47 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/27 17:13:04 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_game *para)
{
	if (para->on_exit == 1)
		para->map[para->player_y][para->player_x] = 'E';
	if (para->on_exit == 0)
		para->map[para->player_y][para->player_x] = '0';
	para->on_exit = 0;
}

void	move_monster(t_game *para)
{
	struct timeval	tv;
	int				i;

	if (para->dead == 1)
		return ;
	i = 0;
	gettimeofday(&tv, NULL);
	para->monster_next_move = (tv.tv_usec + 1) % 4;
	para->time_m = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	if (para->time_m - para->monster_move > MONSTER_SPEED)
	{
		while_monster(para, tv, i);
	}
}

void	monster_check(t_game *para, int y, int x)
{
	if (para->map[y][x] == 'M')
	{
		para->dead = 1;
		display_map(para);
		you_died(para);
		return ;
	}
}

void	next_move_monster(t_game *para, int i)
{
	if (para->monster_next_move == LOOK_DOWN)
	{
		para->new_y_m = para->monster_y[i] + 1;
		para->new_x_m = para->monster_x[i];
	}
	else if (para->monster_next_move == LOOK_UP)
	{
		para->new_y_m = para->monster_y[i] - 1;
		para->new_x_m = para->monster_x[i];
	}
	else if (para->monster_next_move == LOOK_LEFT)
	{
		para->new_y_m = para->monster_y[i];
		para->new_x_m = para->monster_x[i] - 1;
	}
	else if (para->monster_next_move == LOOK_RIGHT)
	{
		para->new_y_m = para->monster_y[i];
		para->new_x_m = para->monster_x[i] + 1;
	}
}

void	while_monster(t_game *para, struct timeval tv, int i)
{
	while (i < para->monster_count)
	{
		para->monster_next_move = (tv.tv_usec + i) % 4;
		para->monster_move = para->time_m;
		next_move_monster(para, i);
		if (para->map[para->new_y_m][para->new_x_m] == 'P')
		{
			para->dead = 1;
			return ;
		}
		if (para->map[para->new_y_m][para->new_x_m] == 'E'
			|| para->map[para->new_y_m][para->new_x_m] == 'M'
			|| para->map[para->new_y_m][para->new_x_m] == 'C'
			|| para->map[para->new_y_m][para->new_x_m] == '1')
		{
			i++;
			continue ;
		}
		para->map[para->monster_y[i]][para->monster_x[i]] = '0';
		para->map[para->new_y_m][para->new_x_m] = 'M';
		para->monster_y[i] = para->new_y_m;
		para->monster_x[i] = para->new_x_m;
		i++;
	}
}
