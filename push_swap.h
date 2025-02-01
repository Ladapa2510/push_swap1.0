/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ladapa2510@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:58:13 by ludomsak          #+#    #+#             */
/*   Updated: 2025/01/31 00:34:44 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				number;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_last(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);
t_stack	*stack_new(int nbr);
void	stack_addfront(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	print_stack(t_stack *stack);

void	swap(t_stack **s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	push(t_stack **top, t_stack **new);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack_r);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack**a, t_stack **b);

void	reverse_rotate(t_stack **stack_rr);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **a, t_stack **b);

void    sort_two(t_stack *stack_a);
void    sort_three(t_stack *stack_a);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void    sort_hundred(t_stack *stack_a, t_stack *stack_b);
void    radix_sort(t_stack *stack_a, t_stack *stack_b);

void	parse(int argc, char *argv[]);


#endif