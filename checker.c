/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:44:12 by abablil           #+#    #+#             */
/*   Updated: 2024/01/15 22:52:15 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_swap **stack_a, t_swap **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
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
	if (is_sorted(&stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
