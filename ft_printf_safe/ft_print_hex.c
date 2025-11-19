/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:52:07 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 19:26:50 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_base(unsigned int n, char *base, int *count)
{
	if (n >= 16)
	{
		if (hexa_base(n / 16, base, count) == -1)
			return (-1);
	}
	return (ft_print_char(base[n % 16], count));
}

int	ft_print_hex(unsigned int n, int c, int *count)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	return (hexa_base(n, base, count));
}
