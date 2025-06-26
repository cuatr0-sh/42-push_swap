/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:33:21 by asoria            #+#    #+#             */
/*   Updated: 2025/06/24 04:14:57 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	char **array_str;
	char *str;

	array_str = "hello world";
	str = ft_split(array_str, ' ');
	printf(str);
	
	/*
	int		i;
	int		stack_size;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	stack_a = ((void *)0);
	stack_b = ((void *)0);
	while (i < argc)
	{
		parse_numbers(argv[i], &stack_a);
	}
	*/
	
}
