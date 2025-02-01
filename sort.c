#include "push_swap.h"

void    sort_two(t_stack *stack_a)
{
    if (stack_a->number > stack_a->next->number)
        sa(stack_a);
}

void    sort_three(t_stack *stack_a)
{
    if ((stack_a->number > stack_a->next->number) && (stack_a->number > stack_a->next->next->number))
        ra(stack_a);
    if ((stack_a->next->next->number > stack_a->next->number) && stack_a->next->next->number > stack_a->next->next->next->number)
        rra(stack_a);
    if (stack_a->next->number > stack_a->next->next->number)
        sa(stack_a);
}
void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int min;

    min = stack_a->index - 3;
    while (stack_a->index > 3)
    {
        if (stack_a->number == min || stack_a->number == min + 1)
            pb(stack_a, stack_b);
       else if (stack_a->number == min + 2 || stack_a->number == min + 3)
       {
           pb(stack_a, stack_b);
           ra(stack_a);
       }
    }
    sort_three(stack_a);
    while (stack_b && stack_b->index > 0)
        pa(stack_a, stack_b);
}

void    sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
    int size;

    size = stack_a->index;
    while (stack_a->index > 3 && stack_a->next->number != size)
    {
        if (stack_a->next->number < size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
    pb(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b->index > 0)
        pa(stack_a, stack_b);
}
void    radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max;
    int i;
    int j;

    max = stack_a->index;
    i = 0;
    j = stack_a->index;
    while (i < max)
    {
        while (j < 0)
        {
            if (((stack_a->number >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (stack_b->index > 0)
            pa(stack_a, stack_b);
        i++;
    }
 }
 