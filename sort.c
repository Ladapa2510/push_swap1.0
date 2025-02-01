/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ludomsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:45:59 by ludomsak          #+#    #+#             */
/*   Updated: 2025/02/01 21:21:08 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	three_sort(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a > b && b > c)
		sa(stack_a);
	else if (a > b && b < c && a < c)
		ra(stack_a);
	else if (a > b && b < c && a > c)
		rra(stack_a);
	else if (a < b && a > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	else if ((*stack_a)->number < (*stack_a)->next->number 
		&& (*stack_a)->next->number < (*stack_a)->next->next->number)
		pb(stack_a, stack_b);
	three_sort(stack_a);
	if ((*stack_b)->number < (*stack_b)->next->number)
		pa(stack_b, stack_a);
}

int	main()
{
	t_stack *a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	stack_addback(&a, stack_new(8));
	stack_addback(&a, stack_new(3));
	stack_addback(&a, stack_new(2));
	stack_addback(&a, stack_new(4));
	stack_addback(&a, stack_new(1));
	five_sort(&a, &b);
	return (0);
}
