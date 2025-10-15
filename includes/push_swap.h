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

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* Typedefs and structures */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//		PARSING, MODIFYING AND FREEING
int		ft_parse_args(int argc, char **argv, t_stack **a);
int		ft_get_stack_size(t_stack *stack);
void	ft_index_stack(t_stack *a);
void	ft_append_stack(t_stack **stack, t_stack *new);
void	ft_free_stack(t_stack **stack);
void	ft_print_stack(t_stack *stack);
t_stack	*ft_create_node(int value);

//		SWAP
int		do_sa(t_stack **a);
int		do_sb(t_stack **b);
int		do_ss(t_stack **a, t_stack **b);
void	do_swap(t_stack **stack);

//		PUSH
int		do_pa(t_stack **a, t_stack **b);
int		do_pb(t_stack **a, t_stack **b);

// 		ROTATE
int		do_ra(t_stack **a);
int		do_rb(t_stack **b);
int		do_rr(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **stack);

//		REVERSE ROTATE
int		do_rra(t_stack **a);
int		do_rrb(t_stack **b);
int		do_rrr(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **stack);

int		ps_is_sorted(t_stack *a);
int		ft_algorithm(t_stack **a, t_stack **b);
int		get_max_bits(t_stack *a);

void	sort_two(t_stack **a);
void	sort_three(t_stack **b);
void	sort_radix(t_stack **a, t_stack **b);
void	sort_chunks(t_stack **a, t_stack **b);

//		COST ANALYSIS FUNCTIONS
void	calculate_positions(t_stack *stack);
void	assign_target_positions(t_stack **a, t_stack **b);
void	calculate_costs(t_stack **a, t_stack **b);

// 		MOVE EXECUTION FUNCTIONS
void	execute_cheapest_move(t_stack **a, t_stack **b);

//		GREEDY SORT FUNCTION
void	sort_greedy(t_stack **a, t_stack **b);
#endif
