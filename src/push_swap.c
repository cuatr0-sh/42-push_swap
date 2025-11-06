/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:23:19 by asoria            #+#    #+#             */
/*   Updated: 2025/11/06 22:24:13 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ft_parse_args(argc, argv, &a) != 0)
	{
		ft_free_stack(&a);
		return (1);
	}
	ft_index_stack(a);
	ft_algorithm(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
