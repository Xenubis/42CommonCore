/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:43:06 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 16:08:00 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_atoi(char *str)
{
	int i;
	int res;
	int si;
	
	i = 0;
	res = 0;
	si = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			si = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * si);
}

int	is_prime(int nbr)
{
	int i;
	
	if (nbr < 2)
		return (0);
	i = 2;
	while (i < nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int sum;
	int n;

	if (ac != 2 || ft_atoi(av[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	n = ft_atoi(av[1]);
	sum = 0;
	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	ft_putchar('\n');	
}