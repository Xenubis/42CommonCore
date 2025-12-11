/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:59:26 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 12:02:20 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	int first;

	if (ac >= 2)
	{
		i = 0;
		first = 0;
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		j = i;
		while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
			i++;
		while (av[1][i])
		{
			if (av[1][i] != ' ' && av[1][i] != '\t')
			{
				if (first)
					write(1, " ", 1);
				first = 1;
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				{
					write(1, &av[1][i], 1);
					i++;
				}
			}
			else
				i++;
		}
		write(1, " ", 1);
		while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t'))
		{
			write(1, &av[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}