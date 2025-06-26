/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 23:37:59 by asoria            #+#    #+#             */
/*   Updated: 2025/06/24 00:21:26 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

s_stack
{
	int		index;
	int		value;
	struct s_stack	*next;
} t_stack;

int	main(int argc, char **argv);
void	parse_numbers(char *str, t_stack stack);

#endif
