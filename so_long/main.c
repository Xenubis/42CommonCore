/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:21:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 16:17:40 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	para->img_collectible = NULL;
	para->img_exit = NULL;
	para->img_floor = NULL;
	para->img_wall = NULL;
	para->img_minish_down = NULL;
	para->img_minish_left = NULL;
	para->img_minish_right = NULL;
	para->img_minish_up = NULL;
	para->mlx = NULL;
	para->window = NULL;
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
	mlx_hook(para.window, 2, 1L<<0, key_handler, &para);
	mlx_loop(para.mlx);
}
