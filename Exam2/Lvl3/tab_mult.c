/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:56:07 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 18:06:07 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int	res;
	
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_putnbr(int nbr)
{
	char	c;
	
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	int n;

	i = 1;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = ft_atoi(av[1]);
	while (i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(n * i);
		write(1, "\n", 1);
		i++;
	}
}