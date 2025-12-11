/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:08:28 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 12:08:49 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	count(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size = 1;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	long	nb;
	char	*str;
	int		neg;

	size = count((long)n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	nb = n;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		neg = 1;
	}
	str[size] = '\0';
	while (size > (size_t)neg)
	{
		str[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}