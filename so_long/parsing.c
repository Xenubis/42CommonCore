/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:51:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 15:43:02 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_size(t_game *para)
{
	while (para->stock_map && para->stock_map->next)
	{
		if (!(ft_strlen(para->stock_map->content)
				== ft_strlen(para->stock_map->next->content)))
			error_end("Error : size map\n", para);
		para->stock_map = para->stock_map->next;
	}
}

void	do_map(t_game *para)
{
	int		size;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = para->stock_map;
	size = ft_lstsize(para->stock_map);
	para->height = size;
	para->width = ft_strlen(para->stock_map->content);
	valid_size(para);
	para->map = (char **)malloc(sizeof(char *) * (size + 1));
	para->stock_map = tmp;
	while (para->stock_map)
	{
		para->map[i++] = para->stock_map->content;
		para->stock_map = para->stock_map->next;
	}
	para->map[i] = NULL;
	para->stock_map = tmp;
	free_lst(para);
	para->stock_map = NULL;
}

void	do_gnl(int fd, t_game *para)
{
	t_list	*tmp;
	char	*line;

	tmp = NULL;
	para->stock_map = NULL;
	line = get_next_line(fd);
	if (!line)
		error_end("Error : file empty\n", para);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tmp = ft_lstnew(line);
		if (!tmp)
		{
			free(line);
			error_end("Error : malloc failded\n", para);
		}
		ft_lstadd_back(&para->stock_map, tmp);
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_map(t_game *para)
{
	check_carac(para);
	if (para->player_count != 1 || para->exit_count != 1
		|| para->collectible_count < 1)
		error_end("Error : map invalid\n", para);
	check_wall(para);
	flood_fill(para);
}
