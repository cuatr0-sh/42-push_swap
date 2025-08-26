/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:53:24 by asoria            #+#    #+#             */
/*   Updated: 2025/08/14 00:53:31 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;
	
	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] + '-')
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
		val = ft_atoi(argv[i]);
		node = ft_create_node((int)val);
		if (!node || (val < -2147483648 || val > 2147483647))
			return (-1);
		t_stack *tmp = *a;
		while (tmp)
		{
			if (tmp->value == (int)val)
				return (-1);
			tmp = tmp->next;
		}
		ft_append_stack(a, node);
		i++;
	}
	return (0);
}
