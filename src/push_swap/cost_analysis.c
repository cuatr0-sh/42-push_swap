/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:00:00 by asoria            #+#    #+#             */
/*   Updated: 2025/08/28 00:00:00 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_target_position(t_stack *a, int b_index)
{
	int		target_pos;
	int		min_greater;
	t_stack	*tmp;

	target_pos = 0;
	min_greater = INT_MAX;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < min_greater)
		{
			min_greater = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (min_greater == INT_MAX)
	{
		tmp = a;
		while (tmp && tmp->next)
			tmp = tmp->next;
		target_pos = tmp->pos + 1;
	}
	return (target_pos);
}

static void	calculate_cost_b(t_stack *b, int size_b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->pos <= size_b / 2)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = -(size_b - tmp->pos);
		tmp = tmp->next;
	}
}

static void	calculate_cost_a(t_stack *b, int size_a)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->target_pos <= size_a / 2)
			tmp->cost_a = tmp->target_pos;
		else
			tmp->cost_a = -(size_a - tmp->target_pos);
		tmp = tmp->next;
	}
}

void	assign_target_positions(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	calculate_positions(*a);
	calculate_positions(*b);
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->target_pos = find_target_position(*a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}

void	calculate_costs(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = ft_get_stack_size(*a);
	size_b = ft_get_stack_size(*b);
	assign_target_positions(a, b);
	calculate_cost_b(*b, size_b);
	calculate_cost_a(*b, size_a);
}
