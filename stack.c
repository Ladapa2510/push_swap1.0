#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = stack_last(*stack);
	last -> next = new;
	new -> prev = last;
	new->next = NULL;
}

void	stack_addfront(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;	
}

t_stack	*stack_new(int nbr)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp -> index = 0;
	tmp -> number = nbr;
	tmp -> prev = NULL;
	tmp -> next = NULL;
	return (tmp);
}
int	stack_size(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
void	print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		ft_putnbr_fd(temp->number, 1);
		write(1, " ", 1);
		temp= temp->next;
	}
	write(1, "\n", 1);
}