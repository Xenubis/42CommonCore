/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:22:50 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 17:39:47 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atoi(char *str)
{
	int i;
	int	res;
	
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] + '0';
		i++;
	}
	return (res);
}

void put_hex(int nbr)
{
	char	*base;
	
	base = "0123456789abcdef";
	while (nbr >= 16)
		put_hex(nbr / 16);
	nbr = base[nbr % 16];
	write(1, &nbr, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		put_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}