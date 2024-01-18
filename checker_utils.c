/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:10:00 by abablil           #+#    #+#             */
/*   Updated: 2024/01/18 22:11:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_instruction(char *s1, char *s2)
{
	int		i;
	char	*new_s1;

	i = 0;
	new_s1 = ft_strtrim(s1, "\n");
	if (!new_s1)
		return (0);
	while (new_s1[i] && s2[i])
	{
		if (new_s1[i] != s2[i])
		{
			free(new_s1);
			return (0);
		}
		i++;
	}
	if (new_s1[i] != s2[i])
	{
		free(new_s1);
		return (0);
	}
	free(new_s1);
	return (1);
}

void	check_if_sorted(t_swap **stack_a, t_swap **stack_b, char *line)
{
	if (is_sorted(stack_a) && !*stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(line);
	free_list(*stack_a);
	free_list(*stack_b);
	exit(1);
}

void	check_instruction(char *line, char *instructions,
		t_swap **stack_a, t_swap **stack_b)
{
	if (!valid_instruction(line, "sa") && !valid_instruction(line, "sb")
		&& !valid_instruction(line, "ss") && !valid_instruction(line, "pa")
		&& !valid_instruction(line, "pb") && !valid_instruction(line, "ra")
		&& !valid_instruction(line, "rb") && !valid_instruction(line, "rr")
		&& !valid_instruction(line, "rra") && !valid_instruction(line, "rrb")
		&& !valid_instruction(line, "rrr"))
	{
		free(instructions);
		invalid_instruction(stack_a, stack_b, line);
	}
}

void	apply_instruction(char *line, t_swap **stack_a, t_swap **stack_b)
{
	if (valid_instruction(line, "sa"))
		return (checker_swap_a(stack_a));
	else if (valid_instruction(line, "sb"))
		return (checker_swap_b(stack_b));
	else if (valid_instruction(line, "ss"))
		return (checker_swap_a_and_b(stack_a, stack_b));
	else if (valid_instruction(line, "pa"))
		return (checker_push_a(stack_a, stack_b));
	else if (valid_instruction(line, "pb"))
		return (checker_push_b(stack_a, stack_b));
	else if (valid_instruction(line, "ra"))
		return (checker_rotate_a(stack_a));
	else if (valid_instruction(line, "rb"))
		return (checker_rotate_b(stack_b));
	else if (valid_instruction(line, "rr"))
		return (checker_rotate_a_and_b(stack_a, stack_b));
	else if (valid_instruction(line, "rra"))
		return (checker_reverse_rotate_a(stack_a));
	else if (valid_instruction(line, "rrb"))
		return (checker_reverse_rotate_b(stack_b));
	else if (valid_instruction(line, "rrr"))
		return (checker_reverse_rotate_a_and_b(stack_a, stack_b));
	return (invalid_instruction(stack_a, stack_b, line));
}
