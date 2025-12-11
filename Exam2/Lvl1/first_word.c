/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:21:19 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:23 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned int i;
		
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != ' ' || argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
}