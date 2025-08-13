#include "../../includes/push_swap.h"

int	do_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_printf("pa\n");
	if (!b || !(*b))
		return (-1);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	return (1);
}

int	do_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_printf("pb\n");
	if (!a || !(*a))
		return (-1);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	return (1);
}
