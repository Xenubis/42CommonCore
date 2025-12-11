/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:14:53 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 15:23:42 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int check[256] = {0};

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
			check[(int)av[1][i++]] = 1;
		i = 0;
		while (av[2][i])
			check[(int)av[2][i++]] = 1;
		i = 0;
		while (av[1][i])
		{
			if (check[(int)av[1][i]])
			{
				write(1, &av[1][i], 1);
				check[(int)av[1][i]] = 0;
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if(check[(int)av[2][i]])
			{
				write(1, &av[2][i], 1);
				check[(int)av[2][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}