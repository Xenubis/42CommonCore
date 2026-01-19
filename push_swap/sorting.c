/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:54:30 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/14 19:50:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_stack *x)
{
	int	first;
	int	second;
	int	third;

	if (x->size < 2)
		return ;
	first = x->top->content;
	second = x->top->next->content;
	if (x->size == 2)
	{
		if (first > second)
			sa(x);
		return ;
	}
	third = x->top->next->next->content;
	if (first < second && second > third && first < third)
		sort132(x);
	else if (first > second && second < third && first < third)
		sort213(x);
	else if (first > second && second < third && first > third)
		sort312(x);
	else if (first > second && second > third && first > third)
		sort321(x);
	else if (first < second && second > third && first > third)
		sort231(x);
}

static int	pos_value_min(t_stack *x)
{
	t_node	*current;
	int		value_min;
	int		min_p;
	int		p;

	current = x->top;
	value_min = current->content;
	min_p = 0;
	p = 0;
	while (current)
	{
		if (current->content < value_min)
		{
			value_min = current->content;
			min_p = p;
		}
		current = current->next;
		p++;
	}
	return (min_p);
}

void	sorting_5(t_stack *a, t_stack *b)
{
	int	min_p;

	while (a->size > 3)
	{
		min_p = pos_value_min(a);
		if (min_p < a->size / 2)
		{
			while (min_p-- > 0)
				ra(a);
		}
		else if (min_p >= a->size / 2)
		{
			while (min_p++ < a->size)
				rra(a);
		}
		pb(b, a);
	}
	sorting_3(a);
	while (b->size > 0)
		pa(a, b);
}

int	sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current->next)
	{
		if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
