/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:52:07 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/19 11:16:53 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_base(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += hexa_base(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(unsigned int n, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	return (hexa_base(n, base));
}
