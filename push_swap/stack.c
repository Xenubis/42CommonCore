/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:07:08 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/15 16:24:06 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x->top = NULL;
	x->size = 0;
	return (x);
}

void	stack_free(t_stack *x)
{
	t_node	*current;
	t_node	*tmp;

	if (!x)
		return ;
	current = x->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(x);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (sorted(a))
		return ;
	if (a->size <= 3)
		sorting_3(a);
	else if (a->size <= 5)
		sorting_5(a, b);
	else
		radix_sort(a, b);
}

int	stack_add_back(t_stack *a, int value)
{
	t_node	*new_node;
	t_node	*current;

	if (!a)
		return (1);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->content = value;
	new_node->next = NULL;
	if (!a->top)
	{
		a->top = new_node;
		a->size++;
		return (0);
	}
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = new_node;
	a->size++;
	return (0);
}
