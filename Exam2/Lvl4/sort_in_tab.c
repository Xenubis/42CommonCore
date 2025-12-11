/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:23:07 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 15:29:10 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_in_tab(int	*tab, unsigned int size)
{
	int tmp;
	unsigned int i;
	unsigned int j;
	
	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}