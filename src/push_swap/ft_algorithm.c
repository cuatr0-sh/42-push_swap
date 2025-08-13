/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:15:28 by asoria            #+#    #+#             */
/*   Updated: 2025/08/13 14:15:31 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_algorithm(t_stack *a, t_stack *b)
{
	ft_printf("STACK A:\n");
	ft_print_stack(a);
	ft_printf("STACK B:\n");
	ft_print_stack(b);

	do_pb(&a, &b);
	do_pa(&a, &b);

	ft_printf("\nSTACK A:\n");
	ft_print_stack(a);
	ft_printf("STACK B:\n");
	ft_print_stack(b);
	return (0);
}
