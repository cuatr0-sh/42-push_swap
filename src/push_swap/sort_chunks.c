#include "../../includes/push_swap.h"

static int	get_max_index_pos(t_stack *a)
{
	int     pos;
	int     max_pos;
	int     max_idx;
	t_stack *cur;

	pos = 0;
	max_pos = 0;
	max_idx = -1;
	cur = a;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

static void	bring_to_top(t_stack **a, int pos)
{
	int	size;
	int	i;

	size = ft_get_stack_size(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			do_ra(a);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			do_rra(a);
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	size = ft_get_stack_size(*a);
	while (size > 3)
	{
		pos = get_max_index_pos(*a);
		bring_to_top(a, pos);
		do_pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		do_pa(a, b);
}
