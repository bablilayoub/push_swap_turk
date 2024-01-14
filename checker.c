/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:44:12 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 21:53:10 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_swap **stack_a, t_swap **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, "sa", 2))
			swap_a(stack_a);
		else if (!ft_strncmp(line, "sb", 2))
			swap_b(stack_b);
		else if (!ft_strncmp(line, "ss", 2))
			swap_a_and_b(stack_a, stack_b);
		else if (!ft_strncmp(line, "pa", 2))
			push_a(stack_a, stack_b);
		else if (!ft_strncmp(line, "pb", 2))
			push_b(stack_a, stack_b);
		else if (!ft_strncmp(line, "ra", 2))
			rotate_a(stack_a);
		else if (!ft_strncmp(line, "rb", 2))
			rotate_b(stack_b);
		else if (!ft_strncmp(line, "rr", 2))
			reverse_rotate_a_and_b(stack_a, stack_b);
		else if (!ft_strncmp(line, "rra", 2))
			reverse_rotate_a(stack_a);
		else if (!ft_strncmp(line, "rrb", 2))
			reverse_rotate_b(stack_b);
		else if (!ft_strncmp(line, "rrr", 2))
			reverse_rotate_a_and_b(stack_a, stack_b);
		else
			send_error();
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int total, char **args)
{
	t_swap	*stack_a;
	t_swap	*stack_b;

	if (total < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = handle_args(args);
	prepare_stack(&stack_a, args);
	checker(&stack_a, &stack_b);
	return (0);
}
