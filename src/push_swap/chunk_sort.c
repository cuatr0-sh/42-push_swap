/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:45:58 by asoria            #+#    #+#             */
/*   Updated: 2025/10/17 08:10:33 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static void	move_max_to_top(t_stack **b, int max_index)
{
	int	pos;
	int	size;
	t_stack	*tmp;

	pos = 0;
	tmp = *b;
	while (tmp && tmp->index != max_index)
	{
		pos++;
		tmp = tmp->next;
	}
	size = ft_get_stack_size(*b);
	if (pos <= size / 2)
		while ((*b)->index != max_index)
			do_rb(b);
	else
		while ((*b)->index != max_index)
			do_rrb(b);
}

static void push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	start;
	int	end;

	start = 0;
	end = chunk_size;
	while (*a)
	{
		if ((*a)->index >= start && (*a)->index < end)
		{
			do_pb(a, b);
			start++;
			if (*b && (*b)->index < start - (chunk_size / 2))
				do_rb(b);
		}
		else
			do_ra(a);
		if (start >= end)
			end += chunk_size;
	}
}

static void	push_back_sorted(t_stack **a, t_stack **b)
{
	int	max_index;

	while (*b)
	{
		max_index = find_max_index(*b);
		move_max_to_top(b, max_index);
		do_pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = ft_get_stack_size(*a);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	push_chunks(a, b, chunk_size);
	push_back_sorted(a, b);
}