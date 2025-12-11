/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:37:58 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 15:17:12 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	unsigned int bit;

	bit = 0;
	i = 8;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}