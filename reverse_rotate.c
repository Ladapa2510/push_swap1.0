/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ladapa2510@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:23:46 by ludomsak          #+#    #+#             */
/*   Updated: 2025/01/28 21:24:06 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack_rr)
{
	t_stack *last;
	t_stack	*second_last;

	if (!*stack_rr || !(*stack_rr)->next)
		return ;
	second_last = *stack_rr;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next =*stack_rr;
	*stack_rr = last;
}
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}