#include "../includes/push_swap.c"

void	append_node(t_stack *stack, t_node *new)
{
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->prev = stack->tail;
		new->next = stack->head;
		stack->tail->next = new;
		stack->head->prev = new;
		stack->tail = new;
	}
	stack->size++;
}

t_node  *create_node(int value)
{
        t_node  *new;

        new = malloc(sizeof(t_node));
        if (!new)
                exit(EXIT_FAILURE);
        new->value = value;
        new->index = -1;
        new->next = NULL;
        new->prev = NULL;
        return (new);
}
