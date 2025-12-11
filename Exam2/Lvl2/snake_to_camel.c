/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:26:15 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 15:39:18 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == '_')
			{
				i++;
				ft_putchar(toupper(av[1][i]));
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}