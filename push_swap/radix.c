/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:24 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/15 14:52:49 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_stack *a)
{
	t_node	*compare;
	t_node	*current;
	int		rank;

	current = a->top;
	while (current)
	{
		rank = 0;
		compare = a->top;
		while (compare)
		{
			if (current->content > compare->content)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	get_max_bit(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bit;
	int	bit;
	int	i;
	int	size;

	create_index(a);
	size = a->size;
	max_bit = get_max_bit(size);
	bit = 0;
	while (bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			if (!((a->top->index >> bit) & 1))
				pb(b, a);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
