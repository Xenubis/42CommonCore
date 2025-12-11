/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:41:48 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 17:53:00 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] <= 32)
			str[i] -= 32;
		ft_putchar(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		ft_putchar('\n');
	else
	{
		while (i < ac)
		{
			rstr_capitalizer(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
}