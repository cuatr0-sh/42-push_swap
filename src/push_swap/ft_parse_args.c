/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:53:24 by asoria            #+#    #+#             */
/*   Updated: 2025/10/15 17:31:00 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	long	val;
	t_stack	*node;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (-1);
		val = ft_atoi(argv[i]);
		if (val < -2147483648 || val > 2147483647)
			return (-1);
		if (has_duplicate(*a, (int)val))
			return (-1);
		node = ft_create_node((int)val);
		if (!node)
			return (-1);
		ft_append_stack(a, node);
		i++;
	}
	return (0);
}
