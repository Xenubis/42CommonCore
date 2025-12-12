/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:34:33 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/12 14:10:24 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int num;

	i = 2;
	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		while (i <= num)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num != i)
					printf("*");
				num = num / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}