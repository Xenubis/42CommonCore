/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:31:23 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 11:35:14 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int count;
	int i;
	int res;

	count = 0;
	i = 0;
	res = 0;
	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > res)
				res = tab[i];
			i++;
			count++;
		}
		return (res);
	}
	return (0);
}