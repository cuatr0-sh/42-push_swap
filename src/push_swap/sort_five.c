#include "../../includes/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int		min = stack->value;
	int		i = 0;
	int		min_i = 0;

	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_i = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_i);
}

void	sort_five(t_stack **a, t_stack **b)
{
int	size = ft_get_stack_size(*a);
	int	min_index;

	while (size > 3)
	{
		min_index = find_min_index(*a);
		if (min_index == 0)
			do_pb(a, b);
		else if (min_index <= size / 2)
		{
			while (min_index-- > 0)
				do_ra(a);
			do_pb(a, b);
		}
		else
		{
			min_index = size - min_index;
			while (min_index-- > 0)
				do_rra(a);
			do_pb(a, b);
		}
		size--;
	}

	sort_three(a);

	while (*b)
		do_pa(a, b);
}