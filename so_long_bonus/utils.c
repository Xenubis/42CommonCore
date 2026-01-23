/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:18:43 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 19:44:41 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_end(char *msg, t_game *para)
{
	t_list	*tmp;

	if (para->stock_map != NULL && para->map == NULL)
	{
		while (para->stock_map)
		{
			tmp = para->stock_map->next;
			free(para->stock_map->content);
			free(para->stock_map);
			para->stock_map = tmp;
		}
	}
	if (para->map != NULL)
	{
		free_tab(para->map);
		if (para->stock_map != NULL)
		{
			free_lst(para);
		}
	}
	write(2, msg, (ft_strlen(msg)));
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_lst(t_game *para)
{
	t_list	*tmp;

	while (para->stock_map)
	{
		tmp = para->stock_map->next;
		free(para->stock_map);
		para->stock_map = tmp;
	}
}

int	end_game(t_game *para)
{
	destroy_minish(para);
	mlx_destroy_image(para->mlx, para->img_wall);
	mlx_destroy_image(para->mlx, para->img_collectible);
	mlx_destroy_image(para->mlx, para->img_exit);
	mlx_destroy_image(para->mlx, para->img_floor);
	mlx_destroy_window(para->mlx, para->window);
	free_tab(para->map);
	mlx_destroy_display(para->mlx);
	free(para->mlx);
	exit(0);
	return (0);
}

void	destroy_minish(t_game *para)
{
	mlx_destroy_image(para->mlx, para->img_minish_down[0]);
	mlx_destroy_image(para->mlx, para->img_minish_down[1]);
	mlx_destroy_image(para->mlx, para->img_minish_down[2]);
	mlx_destroy_image(para->mlx, para->img_minish_exit[0]);
	mlx_destroy_image(para->mlx, para->img_minish_exit[1]);
	mlx_destroy_image(para->mlx, para->img_minish_exit[2]);
	mlx_destroy_image(para->mlx, para->img_minish_up[0]);
	mlx_destroy_image(para->mlx, para->img_minish_up[1]);
	mlx_destroy_image(para->mlx, para->img_minish_up[2]);
	mlx_destroy_image(para->mlx, para->img_minish_left[0]);
	mlx_destroy_image(para->mlx, para->img_minish_left[1]);
	mlx_destroy_image(para->mlx, para->img_minish_left[2]);
	mlx_destroy_image(para->mlx, para->img_minish_right[0]);
	mlx_destroy_image(para->mlx, para->img_minish_right[1]);
	mlx_destroy_image(para->mlx, para->img_minish_right[2]);
}
