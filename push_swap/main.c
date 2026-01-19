/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:00:35 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/15 16:30:09 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_split(char *av, t_stack *a, t_stack *b, int error)
{
	char	**args;
	int		num;
	int		i;

	i = 0;
	args = ft_split(av, ' ');
	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		check_split(args, a, b, is_digit(args[i]));
		error = 0;
		num = atoi_safe(args[i], &error);
		check_split(args, a, b, error);
		check_split(args, a, b, stack_add_back(a, num));
		i++;
	}
	free_all_args(args);
}

void	parsing(int ac, char **av, t_stack *a, t_stack *b)
{
	int	error;
	int	i;

	i = 1;
	error = 0;
	while (i < ac)
	{
		setup_split(av[i], a, b, error);
		i++;
	}
	if (duplicate(a))
		error_end(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
	{
		write(2, "Insert two or more arguments\n", 29);
		exit(EXIT_FAILURE);
	}
	a = stack_new();
	b = stack_new();
	if (!a || !b)
	{
		stack_free(a);
		stack_free(b);
		return (1);
	}
	parsing(ac, av, a, b);
	sort_stack(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
