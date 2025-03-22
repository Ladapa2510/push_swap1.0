/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ladapa2510@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:25:02 by ludomsak          #+#    #+#             */
/*   Updated: 2025/01/31 00:13:23 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h>

void	push_b_helper(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->number >= start && (*stack_a)->number <= end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	start;
	int	end;

	start = size / 4;
	end = (3 * size) / 4;
	push_b_helper(stack_a, stack_b, start, end);
}

void	push_a_helper(t_stack **stack_a, t_stack **stack_b, int *min, int *max)
{
	int	num;
	int	closet_max;
	
	while (*stack_b)
	{
		num = (*stack_b)->number;
		closet_max = find_closet_max(*stack_a, number);
		while ((*stack_a)->number != closet_max)
		{
			if (closer_top(stack_a, closet_max))
				ra(stack_a);
			else
				rra(stack_a);
		}
		pa(stack_a, stack_b);
		if ((*stack_a)->number < *min)
			*min = (*stack_a)->number;
		if ((*stack_a)->number > *max)
			*max = (*stack_a)->number;
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	update_min_max(*stack_a, &min, &max);
	push_a_helper(stack_a, stack_b, &min, &max);
}

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 5)
		sort_five(stack_a, &stack_b);
	else
	{
		push_to_b(stack_a, &stack_b, size);
		sort_three(stack_a);
		push_to_a(stack_a, &stack_b);
		finalize_a(stack_a);
	}
}
