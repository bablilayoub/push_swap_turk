/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_more_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:46:15 by abablil           #+#    #+#             */
/*   Updated: 2024/01/18 22:00:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	invalid_instruction(t_swap **stack_a, t_swap **stack_b, char *line)
{
	free_list(*stack_a);
	free_list(*stack_b);
	free(line);
	send_error();
}

void	checker_reverse_rotate_a_and_b(t_swap **stack_a, t_swap **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		reverse_rotate(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		reverse_rotate(stack_b);
}
