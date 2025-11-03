/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:54:55 by asoria            #+#    #+#             */
/*   Updated: 2025/08/14 00:54:56 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_printf("pa\n");
	if (!b || !(*b))
		return (0);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	return (1);
}

int	do_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return (0);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
	return (1);
}
