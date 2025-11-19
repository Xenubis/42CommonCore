/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:48:25 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 18:44:31 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char c, va_list args, int *count)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int), count));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *), count));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int), count));
	if (c == 'u')
		return (ft_print_unbr(va_arg(args, unsigned int), count));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long), count));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c, count));
	if (c == '%')
		return (ft_print_char('%', count));
	return (0);
}
