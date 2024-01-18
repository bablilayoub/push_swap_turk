/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:04:33 by abablil           #+#    #+#             */
/*   Updated: 2024/01/18 21:59:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_swap_a(t_swap **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
}

void	checker_swap_b(t_swap **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
}

void	checker_swap_a_and_b(t_swap **stack_a, t_swap **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		swap(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		swap(stack_b);
}

void	checker_push_a(t_swap **stack_a, t_swap **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a)
		return ;
	push(stack_b, stack_a);
}

void	checker_push_b(t_swap **stack_a, t_swap **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	push(stack_a, stack_b);
}
