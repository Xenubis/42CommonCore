/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:00:49 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/15 15:51:05 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*STRUCTURE*/

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				index;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/*MAIN*/

int					main(int ac, char **av);
void				parsing(int ac, char **av, t_stack *a, t_stack *b);
void				setup_split(char *av, t_stack *a, t_stack *b, int error);

/*RADIX*/

void				radix_sort(t_stack *a, t_stack *b);
int					get_max_bit(int size);
void				create_index(t_stack *a);

/*OPERATION*/

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *b, t_stack *a);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*SORTING*/

void				sorting_3(t_stack *x);
void				sorting_5(t_stack *a, t_stack *b);
int					sorted(t_stack *a);

void				sort132(t_stack *x);
void				sort213(t_stack *x);
void				sort231(t_stack *x);
void				sort321(t_stack *x);
void				sort312(t_stack *x);

/*UTILS*/

int					atoi_safe(const char *str, int *error);
void				error_end(t_stack *a, t_stack *b);
int					duplicate(t_stack *a);
int					is_digit(char *str);
char				**ft_split(char *str, char c);
void				check_split(char **args, t_stack *a, t_stack *b, int error);
void				free_all_args(char **args);

/*STACK*/

t_stack				*stack_new(void);
void				stack_free(t_stack *x);
int					stack_add_back(t_stack *a, int value);
void				sort_stack(t_stack *a, t_stack *b);

#endif