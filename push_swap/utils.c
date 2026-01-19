/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:54:44 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/15 16:38:20 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	atoi_safe_2(const char *str, int si, long res, int *error)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (str[i] - '0');
		if (((si == 1) && (res > INT_MAX)) || ((si == -1) && ((res * -1) < INT_MIN)))
			*error = 1;
		i++;
	}
	return (res);
}

int	atoi_safe(const char *str, int *error)
{
	int		si;
	int		i;
	long	res;

	i = 0;
	si = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			si *= -1;
		i++;
	}
	if (!str[i])
		*error = 1;
	res = atoi_safe_2((str + i), si, res, error);
	return ((int)res * si);
}

void	error_end(t_stack *a, t_stack *b)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	duplicate(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	if (!a)
		return (1);
	current = a->top;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->content == next->content)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
