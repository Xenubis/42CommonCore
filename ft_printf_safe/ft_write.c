/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:10:41 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 19:11:35 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *ptr, size_t len, int *count)
{
	ssize_t	w;

	w = write(1, ptr, len);
	if (w == -1)
		return (-1);
	*count += w;
	return (0);
}
