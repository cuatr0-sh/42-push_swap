/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:00:00 by asoria            #+#    #+#             */
/*   Updated: 2025/08/28 00:00:00 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_a(t_stack **a, int cost)
{
	while (cost > 0)
	{
		do_ra(a);
		cost--;
	}
	while (cost < 0)
	{
		do_rra(a);
		cost++;
	}
}

static void	rotate_b(t_stack **b, int cost)
{
	while (cost > 0)
	{
		do_rb(b);
		cost--;
	}
	while (cost < 0)
	{
		do_rrb(b);
		cost++;
	}
}

static int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	execute_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b) < cheapest)
		{
			cheapest = absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
	do_pa(a, b);
}
