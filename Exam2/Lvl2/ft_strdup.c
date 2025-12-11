/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:28:50 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/09 16:33:41 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char 	*tmp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	tmp = malloc(sizeof(char) *len + 1);
	if (!tmp)
		return (NULL);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}