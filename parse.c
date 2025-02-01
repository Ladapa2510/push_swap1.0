#include "push_swap.h"

void    parse(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        if (ft_isdigit(argv[i]))
            ft_atoi(argv[i]);
    }
    if (a > b)
        push_swap(a, b);
}