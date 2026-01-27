/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:49:50 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/14 11:22:29 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t len)
{
	size_t	sum;
	void	*p;

	if (len)
	{
		if (__SIZE_MAX__ / len < num)
			return (NULL);
	}
	if (num)
	{
		if (__SIZE_MAX__ / num < len)
			return (NULL);
	}
	sum = num * len;
	p = malloc(sum);
	if (!p)
		return (NULL);
	ft_memset(p, 0, sum);
	return (p);
}
