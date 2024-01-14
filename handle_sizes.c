/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:16:03 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 17:29:50 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	handle_two(t_swap **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		swap_a(stack);
}

void	handle_three(t_swap **stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (!stack || !(*stack))
		return ;
	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		swap_a(stack);
	else if (top > middle && middle > bottom)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate_a(stack);
}
