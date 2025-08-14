/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:52:41 by asoria            #+#    #+#             */
/*   Updated: 2025/08/14 00:52:42 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

int	do_ra(t_stack **a)
{
	ft_printf("ra\n");
	return (ft_rotate(a));
}

int	do_rb(t_stack **b)
{
	ft_printf("rb\n");
	return (ft_rotate(b));
	return (1);
}

int	do_rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	ft_rotate(a);
	ft_rotate(b);
	return (1);
}
