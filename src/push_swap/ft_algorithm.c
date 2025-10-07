/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:15:28 by asoria            #+#    #+#             */
/*   Updated: 2025/08/13 14:15:31 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		do_sa(a);
}

void	sort_three(t_stack **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f > s && f < t)
		do_sa(a);
	else if (f > s && s > t)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (f > s && s < t && f > t)
		do_ra(a);
	else if (f < s && f > t)
		do_rra(a);
	else if (f < s && s > t && f < t)
	{
		do_sa(a);
		do_ra(a);
	}
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	ft_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_stack_size(*a);
	if (ps_is_sorted(*a))
		return (0);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 100)
		sort_radix(a, b);
	else
		sort_radix(a, b);
	return (0);
}
