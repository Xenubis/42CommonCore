/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:42:55 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/11 13:48:55 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	dest_len;
	size_t	j;
	size_t	i;

	dest_len = ft_strlen(dest);
	j = 0;
	while (dest[j])
		j++;
	i = 0;
	while (src[i] && (i + j + 1) < len)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (i < len)
		dest[j + i] = '\0';
	if (len <= dest_len)
		return (ft_strlen(src) + len);
	else
		return (ft_strlen(src) + dest_len);
}
