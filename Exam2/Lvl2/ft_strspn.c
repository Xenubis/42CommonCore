/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:17:56 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 15:38:10 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t j;

	i = 0;
	while (s[i])
	{
		j = 0;
        while (accept[j] && s[i] != accept[j])
            j++;
        if (accept[j] == '\0')
            return (i);
        i++;
	}
	return (i);
}

int main(void)
{
	const char *s = "abcde123";
	const char *accept = "uebcbscd1";
	
	size_t res = ft_strspn(s, accept);
	
	printf("%zu", res);
	return (0);
}