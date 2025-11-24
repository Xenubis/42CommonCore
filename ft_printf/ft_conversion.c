/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:48:25 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 16:00:00 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list args, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unbr(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}
