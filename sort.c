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

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->number;
	mid = (*stack_a)->next->number;
	bottom = (*stack_a)->next->next->number;
	if (top > mid && mid < bottom)
		sa(stack_a);
	else if (top > mid && mid > bottom && top < mid)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bottom)
		ra(stack_a);
	else if (top < mid && mid > bottom && top > mid)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom)
		rra(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min1;
	int	min2;

	find_two_min(*stack_a, &min1, &min2);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->number == min1 || (*stack_a)->number == min2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->next && (*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
	}
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	start;

	start = 0;
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->number <= start && (*stack_a)->number < start + size)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	start += size;
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->next && (*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
	}
}

