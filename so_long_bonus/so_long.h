/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:58:17 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 20:16:15 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ANIMATION_SPEED 500

typedef enum
{
	LOOK_DOWN,
	LOOK_UP,
	LOOK_LEFT,
	LOOK_RIGHT
}			dir;

typedef struct z_game
{
	char	**map;
	t_list	*stock_map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_count;
	int		collectible;
	int		player_count;
	int		move;
	int		collectible_count;
	int		on_exit;
	int		minish_on_exit;
	int		win;
	int		player_dir;
	void	*mlx;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_collectible;
	int		order[8];
	void	*img_minish_down[3];
	void	*img_minish_up[3];
	void	*img_minish_left[3];
	void	*img_minish_right[3];
	void	*img_minish_exit[3];
	int		current_frame;
	long	last_frame;

}			t_game;

/*MAIN*/

int			main(int ac, char **av);
int			setup(int ac, char **av, t_game *para);
void		init_para(t_game *para);
void		init_img(t_game *para);
void		init_minish(t_game *para);

/*PARSING*/

void		do_gnl(int fd, t_game *para);
void		do_map(t_game *para);
void		valid_size(t_game *para);
void		check_map(t_game *para);
void		check_carac(t_game *para);
void		check_wall(t_game *para);
void		flood_fill(t_game *para);

/*MLX*/

void		do_mlx(t_game *para);
void		mlx_create_img(t_game *para);
void		display_map(t_game *para);
void		gg(t_game *para);
int			display_move(t_game *para);
void		display_map_exec(t_game *para, int x, int y);
void		sprite_dir(t_game *para, int x, int y);
void		mlx_create_caracter(t_game *para);
void		mlx_create_caracter2(t_game *para);
void		mlx_create_add(t_game *para);
int			animation(t_game *para);

/*Key*/

int			key_handler(int keycode, t_game *para);
void		move_up(t_game *para);
void		move_down(t_game *para);
void		move_left(t_game *para);
void		move_right(t_game *para);
void		check_exit(t_game *para);
void		move_number(t_game *para);

/*UTILS*/

void		error_end(char *msg, t_game *para);
void		free_lst(t_game *para);
void		free_tab(char **tab);
int			end_game(t_game *para);
void		destroy_minish(t_game *para);

#endif