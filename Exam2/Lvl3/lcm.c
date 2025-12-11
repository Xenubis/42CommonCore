/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:55:14 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/10 16:59:06 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int d;
	
	if (a == 0 || b == 0)
		return (0);
	d = 2;
	while (1)
	{
		if (a % d == 0 && b % d == 0)
			return (d);
		else if (d > a || d > b)
			return (1);
		d++;
	}
}