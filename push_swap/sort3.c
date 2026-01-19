/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:45:56 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/13 17:56:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort132(t_stack *x)
{
	rra(x);
	sa(x);
}

void	sort213(t_stack *x)
{
	sa(x);
}

void	sort231(t_stack *x)
{
	rra(x);
}

void	sort321(t_stack *x)
{
	sa(x);
	rra(x);
}

void	sort312(t_stack *x)
{
	ra(x);
}
