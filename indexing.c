/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:38:27 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 19:52:23 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_swap *stack)
{
	t_swap	*temp_list;
	int		stack_size;
	int		median;
	int		i;

	if (!stack)
		return ;
	i = 0;
	temp_list = stack;
	stack_size = list_size(stack);
	median = stack_size / 2;
	while (temp_list)
	{
		temp_list->index = i;
		if (i <= median)
			temp_list->above_median = 1;
		else
			temp_list->above_median = 0;
		i++;
		temp_list = temp_list->next;
	}
}

void	set_index_value(t_swap *stack)
{
	t_swap	*temp_list;
	int		i;
	int		min_value;

	temp_list = stack;
	min_value = get_min_value(stack);
	i = 0;
	while (temp_list)
	{
		if (temp_list->value == min_value && temp_list->index_value == -1)
		{
			temp_list->index_value = i;
			i++;
			min_value = next_min_value(stack, min_value);
			temp_list = stack;
		}
		else
			temp_list = temp_list->next;
	}
}
