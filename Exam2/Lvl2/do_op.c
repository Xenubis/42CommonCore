/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:48:35 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/09 15:00:55 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (*av[2] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		else if (*av[2] == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		else if (*av[2] == '*')
			printf("%d", atoi(av[1]) * atoi(av[3]));
		else if (*av[2] == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		else if (*av[2] == '%')
			printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	printf("\n");
	return (0);
}