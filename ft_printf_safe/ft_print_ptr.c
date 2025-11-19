/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:28:45 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 19:04:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_base(unsigned long long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (ptr_base(n / 16, count) == -1)
			return (-1);
	}
	return (ft_print_char(base[n % 16], count));
}

int	ft_print_ptr(unsigned long long ptr, int *count)
{
	if (!ptr)
		return (ft_print_str("(nil)", count));
	if (ft_print_str("0x", count) == -1)
		return (-1);
	return (ptr_base(ptr, count));
}
