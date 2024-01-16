/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:56:35 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 17:05:00 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_min_value(t_swap *stack, int min_value)
{
	t_swap	*temp_list;
	int		next_min_value;

	temp_list = stack;
	next_min_value = INT_MAX;
	while (temp_list)
	{
		if (temp_list->value > min_value && temp_list->value < next_min_value)
			next_min_value = temp_list->value;
		temp_list = temp_list->next;
	}
	return (next_min_value);
}

int	get_min_index_value(t_swap *stack)
{
	t_swap	*temp_list;
	int		min_index_value;

	temp_list = stack;
	min_index_value = INT_MAX;
	while (temp_list)
	{
		if (temp_list->index_value < min_index_value)
			min_index_value = temp_list->index_value;
		temp_list = temp_list->next;
	}
	return (min_index_value);
}

int	get_max_index_value(t_swap *stack)
{
	t_swap	*temp_list;
	int		max_index_value;

	temp_list = stack;
	max_index_value = 0;
	while (temp_list)
	{
		if (temp_list->index_value > max_index_value)
			max_index_value = temp_list->index_value;
		temp_list = temp_list->next;
	}
	return (max_index_value);
}
