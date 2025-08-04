/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 03:36:54 by asoria            #+#    #+#             */
/*   Updated: 2025/08/03 18:58:26 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_init_stack(t_stack *stack, char **argv)
{
	int	i;
	int	value;
	t_node	*new;

	i = 1;
	ft_init_stack_empty(stack);
	while(argv[i])
	{
		ft_printf("%d: %s\n", i, argv[i]);
		value = ft_atoi(argv[i]);
		new = ft_create_node(value);
		ft_append_node(stack, new);
		i++;
	}
	return (0);
}
