/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:32:32 by asoria            #+#    #+#             */
/*   Updated: 2025/10/22 20:41:23 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int		min;
	int		i;
	int		min_i;

	min = stack->value;
	i = 0;
	min_i = 0;
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

static void	push_min_to_b(t_stack **a, t_stack **b, int size)
{
	int	min_index;
	int	i;

	min_index = find_min_index(*a);
	if (min_index == 0)
		do_pb(a, b);
	else if (min_index <= size / 2)
	{
		i = min_index;
		while (i-- > 0)
			do_ra(a);
		do_pb(a, b);
	}
	else
	{
		i = size - min_index;
		while (i-- > 0)
			do_rra(a);
		do_pb(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_stack_size(*a);
	while (size > 3)
	{
		push_min_to_b(a, b, size);
		size--;
	}
	sort_three(a);
	while (*b)
		do_pa(a, b);
}
