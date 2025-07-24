/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:17:28 by asoria            #+#    #+#             */
/*   Updated: 2025/07/24 00:13:21 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	ft_error(int error);
void	ft_print_stack(t_stack *stack);
t_stack	ft_parse_args(int argc, char **argv);

#endif
