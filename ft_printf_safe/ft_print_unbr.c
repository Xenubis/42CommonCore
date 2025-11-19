/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:59:26 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 18:33:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int n, int *count)
{
	char	c;

	if (n > 9)
	{
		if (ft_print_unbr(n / 10, count) == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	return (ft_print_char(c, count));
}
