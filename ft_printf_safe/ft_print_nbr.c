/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:46:12 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 19:14:35 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n, int *count)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		if (ft_print_char('-', count) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		if (ft_print_nbr(nb / 10, count) == -1)
			return (-1);
	}
	c = (nb % 10) + '0';
	return (ft_print_char(c, count));
}
