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

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

int	do_ra(t_stack **a)
{
	ft_printf("ra\n");
	ft_rotate(a);
	return (1);
}

int	do_rb(t_stack **b)
{
	ft_printf("rb\n");
	ft_rotate(b);
	return (1);
}

int	do_rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	ft_rotate(a);
	ft_rotate(b);
	return (1);
}
