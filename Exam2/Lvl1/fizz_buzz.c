/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz_buzz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:24:20 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/08 16:34:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			ft_putchar("fizzbuzz");
		else if (i % 3 == 0)
			ft_putchar("fizz");
		else if (i % 5 == 0)
			ft_putchar("buzz");
		else
			ft_putnbr(i);
		i++;
		ft_putchar("\n");
	}
}