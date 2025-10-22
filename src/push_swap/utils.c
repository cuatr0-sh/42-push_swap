/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:59:18 by asoria            #+#    #+#             */
/*   Updated: 2025/10/22 20:28:05 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max_index(t_stack *b)
{
	int		max;
	t_stack	*tmp;

	max = b->index;
	tmp = b->next;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max_index(t_stack *b)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*tmp;

	max = b->index;
	pos = 0;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	move_max_to_top(t_stack **b, int pos)
{
	int	size;

	size = ft_get_stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			do_rb(b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			do_rrb(b);
			pos++;
		}
	}
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ps_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
