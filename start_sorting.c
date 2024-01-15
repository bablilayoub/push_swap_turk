/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:46:02 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 00:13:18 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_pushing(t_swap *cheap_node, t_swap **stack_a, t_swap **stack_b)
{
	if (!cheap_node || !stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	while (*stack_b && *stack_a
		&& (*stack_b != cheap_node && *stack_a != cheap_node->target)
		&& (cheap_node->above_median && cheap_node->target->above_median))
		rotate_a_and_b(stack_a, stack_b);
	while (*stack_b && *stack_a
		&& (*stack_b != cheap_node && *stack_a != cheap_node->target)
		&& (!cheap_node->above_median && !cheap_node->target->above_median))
		reverse_rotate_a_and_b(stack_a, stack_b);
	while (*stack_b && (*stack_b != cheap_node))
	{
		if (cheap_node->above_median)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	while (*stack_a && (*stack_a != cheap_node->target))
	{
		if (cheap_node->target->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
}

void	sort_back(t_swap **stack_a, t_swap **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_targets(stack_a, stack_b, 0);
	start_pushing(set_cost(stack_b, list_size(*stack_a),
			list_size(*stack_b)), stack_a, stack_b);
}

void	move_min_to_top(t_swap **stack_a)
{
	int	min_value;

	if (!stack_a || !*stack_a)
		return ;
	min_value = get_min_value(*stack_a);
	while ((*stack_a)->value != min_value)
	{
		if ((*stack_a)->above_median)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		set_index(*stack_a);
	}
}

void	sort_stack(t_swap **stack_a, t_swap **stack_b)
{
	int	median;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	median = get_median(*stack_a);
	while (list_size(*stack_a) > 3 && !is_sorted(stack_a))
	{
		if ((*stack_a)->value > median)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
			push_b(stack_a, stack_b);
	}
	if (list_size(*stack_a) == 3 && !is_sorted(stack_a))
		handle_three(stack_a);
	while (*stack_b)
		sort_back(stack_a, stack_b);
	set_index(*stack_a);
	move_min_to_top(stack_a);
}

void	start_sorting(t_swap **stack_a, t_swap **stack_b)
{
	int	stack_size;

	if (!stack_a || !*stack_a)
		return ;
	if (is_sorted(stack_a))
	{
		free_list(*stack_a);
		return ;
	}
	stack_size = list_size(*stack_a);
	if (stack_size == 2)
		handle_two(stack_a);
	else if (stack_size == 3)
		handle_three(stack_a);
	else
		sort_stack(stack_a, stack_b);
	free_list(*stack_a);
}
