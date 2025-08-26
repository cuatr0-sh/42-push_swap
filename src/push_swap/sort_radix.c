#include "../../includes/push_swap.h"

static void	radix_pass(t_stack **a, t_stack **b, int i, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = (*a)->index;
		if (((num >> i) & 1) == 1)
			do_ra(a);
		else
			do_pb(a, b);
		j++;
	}
	while (*b)
		do_pa(a, b);
}

void	sort_radix(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;

	size = ft_get_stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i, size);
		i++;
	}
}
