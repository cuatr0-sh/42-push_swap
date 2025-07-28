/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:12:31 by asoria            #+#    #+#             */
/*   Updated: 2025/07/25 00:08:08 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack	b;

	if (argc < 2)
		return (ft_error(1));
	{
	ft_init_stack(&a);
	ft_init_stack_empty(&b);
	a = ft_parse_args(argc, argv);
	return (0);
}
