/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 17:12:13 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int nbr)
{
	char	c;
	
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	(void) av;
	
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}