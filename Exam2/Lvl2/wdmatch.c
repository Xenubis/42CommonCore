/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:42:44 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 14:50:39 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		const char *s1 = av[1];
		const char *s2 = av[2];
		int len;
		int i;

		len = 0;
		i = 0;
		while (s1[len])
			len++;
		while (i < len && *s2)
		{
			if (s1[i] == *s2++)
				i++;
		}
		if (i == len)
			write(1, s1, len);
	}
	write(1, '\n', 1);
	return (0);
}