/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludomsak <ladapa2510@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:22:09 by ludomsak          #+#    #+#             */
/*   Updated: 2025/01/28 01:12:17 by ludomsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push(t_stack **top, t_stack **new)
{
    t_stack  *temp;

    if (!*new)
        return ;
    temp = *new;
    *new = (*new)->next;
    if (*new)
        (*new)->prev = NULL;
    if (!*top)
    {
        *top = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->next = *top;
        temp->prev = NULL;
        (*top)->prev = temp;
        *top = temp;
    }
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}