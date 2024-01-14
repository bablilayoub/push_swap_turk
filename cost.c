/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:35:08 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 01:42:57 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp_b;
	t_swap	*temp_a;
	t_swap	*cheapest_node;
	int		stack_a_size;
	int		stack_b_size;
	int		total_cost;
	int		cheapest;

	temp_b = *stack_b;
	temp_a = *stack_a;
	stack_a_size = list_size(*stack_a);
	stack_b_size = list_size(*stack_b);
	cheapest = INT_MAX;
	while (temp_b)
	{
		if (temp_b->above_median)
			temp_b->push_cost = temp_b->index;
		else
			temp_b->push_cost = stack_b_size - temp_b->index;
		if (temp_b->target->above_median)
			temp_b->target->push_cost = temp_b->target->index;
		else
			temp_b->target->push_cost = stack_a_size - temp_b->target->index;
		total_cost = temp_b->push_cost + temp_b->target->push_cost;
		if (cheapest > total_cost)
		{
			cheapest = total_cost;
			cheapest_node = temp_b;
		}
		temp_b = temp_b->next;
	}
}