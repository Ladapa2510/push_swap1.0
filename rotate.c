/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ladapa2510@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:23:30 by ludomsak          #+#    #+#             */
/*   Updated: 2025/01/28 21:24:40 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack_r)
{
	t_stack	*first;
	t_stack *last;

	if (!*stack_r || !(*stack_r)-> next)
		return ;
	first = *stack_r;
	last = stack_last(*stack_r);
	
	*stack_r = first->next;
	first->next = NULL;
	last->next = first;
}
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack**a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
