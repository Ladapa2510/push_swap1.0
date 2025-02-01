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

#include "push_swap.h"

void   sorting(t_stack *stack_a, t_stack *stack_b)
 {
    if (stack_a->index == 2)
        sort_two(stack_a);
    else if (stack_a->index == 3)
        sort_three(stack_a);
    else if (stack_a->index == 5)
        sort_five(stack_a, stack_b);
    else if (stack_a->index <= 100)
        sort_hundred(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
 }