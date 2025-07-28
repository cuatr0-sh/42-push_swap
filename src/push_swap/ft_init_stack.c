#include "../includes/push_swap.h"

int	ft_init_stack(t_stack *stack, char **argv)
{
	int	i;
	int	value;
	t_node	*new;

	i = 0;
	ft_init_stack_empty(stack);
	while(argv[i])
	{
		value = ft_atoi(argv[i]);
		new = ft_create_node(value);
		ft_append_node(stack, new);
		i++;
	}
}
