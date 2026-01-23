/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:52:15 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/11 15:39:18 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < len)
		i++;
	if (i < len)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
