/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:17:28 by asoria            #+#    #+#             */
/*   Updated: 2025/07/31 04:29:44 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

/* Typedefs and structures */
typedef struct s_node
{
        long                    value;
        long                    index;
        struct s_node   *next;
        struct s_node   *prev;
}       t_node;

typedef struct s_stack
{
        t_node          *head;
        t_node          *tail;
        long int        size;
}       t_stack;

/* Error management and debugging */
int     ft_error(int error);
void    ft_print_stack(t_node *node);

/* Initialization*/
int     ft_init_node(t_node *node);
int     ft_init_stack(t_stack *stack, char **argv);
void	ft_init_stack_empty(t_stack *stack);

t_node	*ft_create_node(int value);
void	ft_append_node(t_stack *stack, t_node *new);

#endif
