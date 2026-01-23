/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:28:31 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/12 16:09:33 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed;
	size_t	len;

	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && is_set(s1[j], set))
		j--;
	len = j - i;
	trimmed = malloc(sizeof(char) * (len + 2));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, len + 1);
	trimmed[len + 1] = '\0';
	return (trimmed);
}
