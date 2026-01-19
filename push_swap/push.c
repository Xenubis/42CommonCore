/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:00:51 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/14 19:22:32 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *x, t_stack *y)
{
	t_node	*tmp;

	if (!y || !y->top)
		return ;
	tmp = y->top;
	y->top = y->top->next;
	y->size--;
	tmp->next = x->top;
	x->top = tmp;
	x->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
