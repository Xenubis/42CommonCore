/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:18:43 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/23 15:37:28 by mmusquer         ###   ########.fr       */
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
