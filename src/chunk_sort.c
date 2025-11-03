/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:25:29 by asoria            #+#    #+#             */
/*   Updated: 2025/10/22 20:32:57 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	if (size <= 20)
		chunk = 5;
	else
		chunk = 20;
	return (chunk);
}

static void	push_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int	scan;
	int	val;

	scan = ft_get_stack_size(*a);
	while (scan > 0)
	{
		val = (*a)->index;
		if (val >= min && val <= max)
			do_pb(a, b);
		else
			do_ra(a);
		scan--;
	}
}

static void	push_chunks(t_stack **a, t_stack **b, int size)
{
	int	chunk;
	int	i;
	int	min;
	int	max;

	chunk = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		min = i;
		max = i + chunk - 1;
		if (max >= size)
			max = size - 1;
		push_chunk(a, b, min, max);
		i = max + 1;
	}
}

static void	push_back_sorted(t_stack **a, t_stack **b)
{
	int	pos;

	while (*b)
	{
		pos = find_max_index(*b);
		move_max_to_top(b, pos);
		do_pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_stack_size(*a);
	push_chunks(a, b, size);
	push_back_sorted(a, b);
}
