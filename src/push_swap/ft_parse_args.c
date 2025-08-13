#include "../../includes/push_swap.h"

int	ft_parse_args(int argc, char **argv, t_stack **a)
{
	int	i;
	t_stack	*node;

	if (argc < 2)
	{
		ft_printf("Error: couldn't parse args");
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		node = ft_create_node(ft_atoi(argv[i]));
		if (!node)
		{
			ft_free_stack(a);
			ft_printf("Error: ft_parse_args: malloc failed");
			return (-2);
		}
		ft_append_stack(a, node);
		i++;
	}
	return (0);
}
