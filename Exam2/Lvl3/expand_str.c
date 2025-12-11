/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:22:48 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 16:23:44 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i;
	int space;

	if (ac == 2)
	{
		space = 0;
		i = 0;
		while (is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (is_space(av[1][i]))
				space = 1;
			if (!is_space(av[1][i]))
			{
				if (space == 1)
					write(1, '   ', 3);
				space = 0;
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
}