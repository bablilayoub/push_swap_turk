/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:33:22 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 17:23:05 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_swap *stack)
{
	int	min_index_value;
	int	max_index_value;

	if (!stack)
		return (0);
	min_index_value = get_min_index_value(stack);
	max_index_value = get_max_index_value(stack);
	return ((min_index_value + max_index_value) / 2);
}

t_swap	*get_min_target(t_swap *stack)
{
	t_swap	*temp_list;
	t_swap	*target;

	if (!stack)
		return (0);
	temp_list = stack;
	target = temp_list;
	while (temp_list)
	{
		if (temp_list->index_value < target->index_value)
			target = temp_list;
		temp_list = temp_list->next;
	}
	return (target);
}

t_swap	*get_max_target(t_swap *stack)
{
	t_swap	*temp_list;
	t_swap	*target;

	if (!stack)
		return (0);
	temp_list = stack;
	target = temp_list;
	while (temp_list)
	{
		if (temp_list->index_value > target->index_value)
			target = temp_list;
		temp_list = temp_list->next;
	}
	return (target);
}

void	set_targets(t_swap **stack_a, t_swap **stack_b, int found_target)
{
	t_swap	*temp_a;
	t_swap	*temp_b;
	t_swap	*target;

	temp_b = *stack_b;
	while (temp_b)
	{
		(1 == 1) && (found_target = 0, temp_a = *stack_a);
		target = get_max_target(*stack_a);
		while (temp_a)
		{
			if (temp_a->index_value > temp_b->index_value
				&& temp_a->index_value <= target->index_value)
			{
				target = temp_a;
				found_target = 1;
			}
			temp_a = temp_a->next;
		}
		if (!found_target)
			temp_b->target = get_min_target(*stack_a);
		else
			temp_b->target = target;
		temp_b = temp_b->next;
	}
}
