#include "../../includes/push_swap.h"

t_stack *create_node(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->value = value;
	node->index = -1;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	return (node);
}

void	append_stack(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if (!stack || !new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;
	
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;
	
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
