#include "../includes/push_swap.h"

void	ft_init_stack_empty(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
