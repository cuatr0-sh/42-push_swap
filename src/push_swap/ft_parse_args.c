/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:27:02 by asoria            #+#    #+#             */
/*   Updated: 2025/07/25 00:08:13 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	ft_parse_args(int argc, char **argv)
{
	t_stack stack;

	stack = (t_stack) {0, 0, NULL, NULL};
	if (argc < 2)
		ft_error(1);
	return (stack);
}
