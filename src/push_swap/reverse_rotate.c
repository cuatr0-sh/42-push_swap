/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:28:34 by asoria            #+#    #+#             */
/*   Updated: 2025/08/14 02:28:36 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	do_rra(t_stack **a)
{
	ft_printf("rra\n");
	return (ft_reverse_rotate(a));
}

int	do_rrb(t_stack **b)
{
	ft_printf("rrb\n");
	return (ft_reverse_rotate(b));
}

int	do_rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	return (1);
}
