/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:28:21 by asoria            #+#    #+#             */
/*   Updated: 2025/10/22 20:29:43 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
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

int	ft_has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	add_number(t_stack **a, char *num)
{
	long	val;
	t_stack	*node;

	val = ft_atol(num);
	if (!is_valid_number(num) || val < -2147483648 || val > 2147483647)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_has_duplicate(*a, (int)val))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	node = ft_create_node((int)val);
	if (!node)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_append_stack(a, node);
	return (0);
}

static int	parse_string(char *arg, t_stack **a)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (ft_free_split(split), -1);
	i = 0;
	while (split[i])
	{
		if (add_number(a, split[i++]) != 0)
			return (ft_free_split(split), -1);
	}
	ft_free_split(split);
	return (0);
}

int	ft_parse_args(int argc, char **argv, t_stack **a)
{
	int	i;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (parse_string(argv[i++], a) != 0)
			return (-1);
	}
	return (0);
}
