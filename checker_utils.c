/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:10:00 by abablil           #+#    #+#             */
/*   Updated: 2024/01/15 21:34:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	*new_s1;

	i = 0;
	new_s1 = ft_strtrim(s1, "\n ");
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

void	invalid_instruction(t_swap **stack_a, t_swap **stack_b, char *line)
{
	free_list(*stack_a);
	free_list(*stack_b);
	free(line);
	send_error();
}

void	checker_reverse_rotate_a_and_b(t_swap **stack_a, t_swap **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
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

void	check_instruction(char *line, t_swap **stack_a, t_swap **stack_b)
{
	if (ft_strcmp(line, "sa"))
		return (checker_swap_a(stack_a));
	else if (ft_strcmp(line, "sb"))
		return (checker_swap_b(stack_b));
	else if (ft_strcmp(line, "ss"))
		return (checker_swap_a_and_b(stack_a, stack_b));
	else if (ft_strcmp(line, "pa"))
		return (checker_push_a(stack_a, stack_b));
	else if (ft_strcmp(line, "pb"))
		return (checker_push_b(stack_a, stack_b));
	else if (ft_strcmp(line, "ra"))
		return (checker_rotate_a(stack_a));
	else if (ft_strcmp(line, "rb"))
		return (checker_rotate_b(stack_b));
	else if (ft_strcmp(line, "rr"))
		return (checker_rotate_a_and_b(stack_a, stack_b));
	else if (ft_strcmp(line, "rra"))
		return (checker_reverse_rotate_a(stack_a));
	else if (ft_strcmp(line, "rrb"))
		return (checker_reverse_rotate_b(stack_b));
	else if (ft_strcmp(line, "rrr"))
		return (checker_reverse_rotate_a_and_b(stack_a, stack_b));
	else if (ft_strcmp(line, "done"))
		return (check_if_sorted(stack_a, stack_b, line));
	return (invalid_instruction(stack_a, stack_b, line));
}
