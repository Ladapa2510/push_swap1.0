/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ludomsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:34:25 by ludomsak          #+#    #+#             */
/*   Updated: 2025/03/22 20:23:49 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack_a)
{
	int	min;

	min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->number < min)
			min = stack_a->number;
		stack_a = stack_a->next;
	}
	return (min);
}

void	find_two_min(t_stack *stack, int *min1, int *min2)
{
	*min1 = INT_MAX;
	*min2 = INT_MAX;
	while (stack)
	{
		if (stack->number < *min1)
		{
			*min2 = *min1;
			*min1 = stack->number;
		}
		else if (stack->number < *min2)
			*min2 = stack->number;
		stack = stack->next;
	}
}

int	find_max(t_stack *stack)
{
	int		max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	return (max);
}

void	update_min_max(t_stack *stack, int *min, int *max)
{
	if (!stack)
	{
		*min = 0;
		*max = 0;
		return ;
	}
	*min = stack->number;
	*max = stack->number;
	while (stack)
	{
		if (stack->number < *min)
			*min = stack->number;
		else if (stack->number > *max)
			*max = stack->number;
		stack = stack->next;
	}
}

void	finalize_a(t_stack **stack_a)
{
	int	min;

	min = find_min(*stack_a);
	while ((*stack_a)->number != min)
	{
		if (closer_top(&stack_a, min))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	find_closet_max(t_stack *stack, int number)
{
	int	closet_max;

	closet_max = INT_MAX;
	while (stack)
	{
		if (stack->number > number && stack->number < closet_max)
			closet_max = stack->number;
		stack = stack->next;
	}
	return (closet_max);
}

int	closer_top(t_stack **stack_a, int target)
{
	int		size;
	int		i;

	size = stack_size(*stack_a);
	i = 0;
	while (stack_a)
	{
		if ((*stack_a)->number == target)
			break;
		i++;
		stack_a = &stack_a;
	}
	if (i <= size / 2)
		return (1);
	else
		return (0);
}

int	find_index(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->number == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	find_hold_first(t_stack *stack, int start, int end, int *hold_first)
{
	int	pos;

	pos = -1;
	*hold_first = 0;
	while (stack)
	{
		if (stack->number >= start && stack->number <= end)
		{
			pos = stack->number;
			break;
		}
		(*hold_first)++;
		stack = stack->next;
	}
	return (pos);
}

int	find_hold_second(t_stack *stack, int start, int end, int *hold_sec)
{
	int	pos;

	pos = -1;
	*hold_sec = stack_size(stack) - 1;
	while (stack)
	{
		if (stack->number >= start && stack->number <= end)
		{
			pos = stack->number;
		}
		stack = stack->next;
	}
	return (pos);
}

void	move_to_top(t_stack **stack_a, int number)
{
	int	pos;
	int	size;

	pos = find_index(*stack_a, number);
	size = stack_size(*stack_a);
	while ((*stack_a)->number != number)
	{
		if (pos <= size/2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
