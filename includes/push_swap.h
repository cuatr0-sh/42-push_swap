/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:17:28 by asoria            #+#    #+#             */
/*   Updated: 2025/08/08 01:13:19 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

/* Typedefs and structures */
typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
        struct s_stack   *next;
}       t_stack;

// PARSING, MODIFYING AND FREEING
t_stack *ft_create_node(int value);
void	ft_append_stack(t_stack **stack, t_stack *new);
int	ft_get_stack_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_print_stack(t_stack *stack);
int	ft_algorithm(t_stack *a, t_stack *b);
int	ft_parse_args(int argc, char **argv, t_stack **a);
// SWAP
void	do_swap(t_stack **stack);
int	do_sa(t_stack **a);
int	do_sb(t_stack **b);
int	do_ss(t_stack **a, t_stack **b);
// PUSH
int	do_pa(t_stack **a, t_stack **b);
int	do_pb(t_stack **a, t_stack **b);

// ROTATE
void	ft_rotate(t_stack **stack);
int	do_ra(t_stack **a);
int	do_rb(t_stack **b);
int	do_rr(t_stack **a, t_stack **b);
// REVERSE ROTATE
void	ft_reverse_rotate();
int	do_rra();
int	do_rrb();

#endif
