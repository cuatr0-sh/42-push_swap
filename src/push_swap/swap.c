#include "../../includes/push_swap.h"

void	do_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		ft_printf("Error: do_swap: the stack was empty or invalid.\n");
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

int	do_sa(t_stack **stack)
{
	ft_printf("sa\n");
	do_swap(stack);
	return (1);
}

int	do_sb(t_stack **stack)
{
	ft_printf("sb\n");
	do_swap(stack);
	return (1);
}

int	do_ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	do_swap(a);
	do_swap(b);
	return (1);
}
