/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_more.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:08:35 by abablil           #+#    #+#             */
/*   Updated: 2024/01/15 19:09:17 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_rotate_a(t_swap **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate(stack_a);
}

void	checker_rotate_b(t_swap **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
}

void	checker_rotate_a_and_b(t_swap **stack_a, t_swap **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

void	checker_reverse_rotate_a(t_swap **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
}

void	checker_reverse_rotate_b(t_swap **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
}
