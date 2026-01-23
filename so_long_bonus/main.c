/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:21:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 20:18:32 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *para)
{
	para->img_collectible = NULL;
	para->img_exit = NULL;
	para->img_floor = NULL;
	para->img_wall = NULL;
	para->mlx = NULL;
	para->window = NULL;
	para->order[0] = 0;
	para->order[1] = 1;
	para->order[2] = 0;
	para->order[3] = 2;
	para->order[4] = 0;
	para->order[5] = 1;
	para->order[6] = 0;
	para->order[7] = 2;
}

void	init_minish(t_game *para)
{
	para->img_minish_down[0] = NULL;
	para->img_minish_down[1] = NULL;
	para->img_minish_down[2] = NULL;
	para->img_minish_exit[0] = NULL;
	para->img_minish_exit[1] = NULL;
	para->img_minish_exit[2] = NULL;
	para->img_minish_up[0] = NULL;
	para->img_minish_up[1] = NULL;
	para->img_minish_up[2] = NULL;
	para->img_minish_left[0] = NULL;
	para->img_minish_left[1] = NULL;
	para->img_minish_left[2] = NULL;
	para->img_minish_right[0] = NULL;
	para->img_minish_right[1] = NULL;
	para->img_minish_right[2] = NULL;
}

void	init_para(t_game *para)
{
	para->stock_map = NULL;
	para->map = NULL;
	para->collectible = 0;
	para->collectible_count = 0;
	para->exit_count = 0;
	para->height = 0;
	para->width = 0;
	para->move = 0;
	para->player_count = 0;
	para->player_x = 0;
	para->player_y = 0;
	para->on_exit = 0;
	para->minish_on_exit = 0;
	para->win = 0;
	para->current_frame = 0;
	para->last_frame = 0;
	para->player_dir = 0;
	init_img(para);
	init_minish(para);
}

int	setup(int ac, char **av, t_game *para)
{
	char	*path;
	int		fd;
	int		i;

	if (ac != 2)
		error_end("Usage : path/namemap.ber\n", para);
	path = av[1];
	i = ft_strlen(path);
	if (i < 5)
		error_end("Usage : path/namemap.ber\n", para);
	i -= 4;
	if (strcmp((path + i), ".ber") != 0)
		error_end("Wrong files type\n", para);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_end("Error opening file\n", para);
	return (fd);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	para;

	init_para(&para);
	fd = setup(ac, av, &para);
	do_gnl(fd, &para);
	do_map(&para);
	check_map(&para);
	do_mlx(&para);
	mlx_hook(para.window, 17, 0, end_game, &para);
	mlx_hook(para.window, 2, 1L << 0, key_handler, &para);
	mlx_loop_hook(para.mlx, animation, &para);
	mlx_loop(para.mlx);
}
