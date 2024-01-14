/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:35:08 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 17:36:58 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*set_cost(t_swap **stack_b, int stack_a_size, int stack_b_size)
{
	t_swap	*temp_b;
	t_swap	*cheapest_node;
	int		cheapest;

	temp_b = *stack_b;
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
		if (cheapest > temp_b->push_cost + temp_b->target->push_cost)
		{
			cheapest = temp_b->push_cost + temp_b->target->push_cost;
			cheapest_node = temp_b;
		}
		temp_b = temp_b->next;
	}
	return (cheapest_node);
}
