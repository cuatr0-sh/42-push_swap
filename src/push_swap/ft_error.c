/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:35:05 by asoria            #+#    #+#             */
/*   Updated: 2025/07/23 00:43:04 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(int error_no)
{
	if (error_no == 1)
		ft_printf("Error: push_swap.c: Too few arguments passed to the program\n");
	else if (error_no == 2)
		ft_printf("Error: ft_init_stack.c: Unable to initialize stack with null values.");
	return (error_no);
}
