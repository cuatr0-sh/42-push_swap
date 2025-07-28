#include "../includes/push_swap.h"

void	ft_init_stack_empty(t_stack stack)
{
	t_stack	*stack;

	stack = malloc(sizeof t_stack);
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}
