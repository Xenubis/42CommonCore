/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:00:01 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/09 17:31:47 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int main (int ac, char **av)
{
	int i;
	int j;
	int	check[256] = {};
	
	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !check[(int)av[2][j]])
				{
					ft_putchar(av[2][j]);
					check[(int)av[2][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
}