/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:44:12 by abablil           #+#    #+#             */
/*   Updated: 2024/01/18 22:09:36 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(char *str, t_swap **stack_a, t_swap **stack_b)
{
	if (str)
		free(str);
	free_list(*stack_a);
	free_list(*stack_b);
	send_error();
}

void	handle_instructions(char *instructions,
		t_swap **stack_a, t_swap **stack_b)
{
	int		i;
	char	**instructions_array;

	i = 0;
	instructions_array = ft_split(instructions, '\n');
	if (!instructions_array)
		free_and_exit(instructions, stack_a, stack_b);
	free(instructions);
	while (instructions_array[i])
	{
		apply_instruction(instructions_array[i], stack_a, stack_b);
		i++;
	}
	free_args(instructions_array);
}

void	checker(t_swap **stack_a, t_swap **stack_b)
{
	char	*line;
	char	*instructions;
	char	*temp;

	instructions = ft_strdup("");
	if (!instructions)
		free_and_exit(NULL, stack_a, stack_b);
	line = get_next_line(0);
	while (line)
	{
		check_instruction(line, instructions, stack_a, stack_b);
		temp = instructions;
		instructions = ft_strjoin(instructions, line);
		if (!instructions)
		{
			free(temp);
			free_and_exit(line, stack_a, stack_b);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!instructions[0])
		free(instructions);
	else
		handle_instructions(instructions, stack_a, stack_b);
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
