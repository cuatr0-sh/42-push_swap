/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:23:19 by asoria            #+#    #+#             */
/*   Updated: 2025/08/08 01:25:45 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*node;
	t_stack	*a;

	a= NULL;
	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		node = ft_create_node(atoi(argv[i]));
		if (!node)
		{
			ft_free_stack(&a);
			return (1);
		}
		ft_append_stack(&a, node);
		i++;
	}
	ft_print_stack(a);
	ft_free_stack(&a);
	return (0);
}
