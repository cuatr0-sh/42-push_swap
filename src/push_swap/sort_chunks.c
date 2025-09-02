/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:00:00 by asoria            #+#    #+#             */
/*   Updated: 2025/08/28 00:00:00 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	size;
	int	pushed;
	int	rotations;
	int	chunk_max;

	size = ft_get_stack_size(*a);
	pushed = 0;
	chunk_max = chunk_size;
	while (pushed < chunk_size && size > 3)
	{
		rotations = 0;
		while ((*a)->index >= chunk_max && rotations < size)
		{
			do_ra(a);
			rotations++;
		}
		if ((*a)->index < chunk_max)
		{
			do_pb(a, b);
			pushed++;
			size--;
		}
	}
}

void	calculate_positions(t_stack *stack)
{
	t_stack	*tmp;
	int		pos;

	tmp = stack;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}

static void	move_to_top_b(t_stack **b, int target_pos)
{
	int	size;
	int	i;

	size = ft_get_stack_size(*b);
	if (target_pos <= size / 2)
	{
		i = 0;
		while (i < target_pos)
		{
			do_rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - target_pos))
		{
			do_rrb(b);
			i++;
		}
	}
}

static void	sort_b_and_push_back(t_stack **a, t_stack **b)
{
	int		max_index;
	int		max_pos;
	t_stack	*tmp;

	while (*b)
	{
		calculate_positions(*b);
		max_index = -1;
		max_pos = 0;
		tmp = *b;
		while (tmp)
		{
			if (tmp->index > max_index)
			{
				max_index = tmp->index;
				max_pos = tmp->pos;
			}
			tmp = tmp->next;
		}
		move_to_top_b(b, max_pos);
		do_pa(a, b);
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	int	total_size;
	int	chunk_size;
	int	chunks_pushed;

	total_size = ft_get_stack_size(*a);
	if (total_size <= 100)
		chunk_size = 20;
	else
		chunk_size = total_size / 5;
	chunks_pushed = 0;
	while (ft_get_stack_size(*a) > 3)
	{
		push_chunks_to_b(a, b, chunk_size);
		chunks_pushed += chunk_size;
	}
	sort_three(a);
	sort_b_and_push_back(a, b);
}
