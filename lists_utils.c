/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:53 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 17:05:51 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_swap *stack)
{
	int		min_index;
	t_swap	*temp_list;

	if (!stack)
		return (0);
	temp_list = stack;
	min_index = temp_list->index;
	while (temp_list)
	{
		if (temp_list->index < min_index)
			min_index = temp_list->index;
		temp_list = temp_list->next;
	}
	return (min_index);
}

int	is_sorted(t_swap **stack)
{
	t_swap	*temp_list;

	if (!stack || !*stack)
		return (0);
	temp_list = *stack;
	while (temp_list->next)
	{
		if (temp_list->index_value > temp_list->next->index_value)
			return (0);
		temp_list = temp_list->next;
	}
	return (1);
}

t_swap	*get_last_list(t_swap *list)
{
	t_swap	*temp_list;

	if (!list)
		return (NULL);
	temp_list = list;
	while (temp_list->next)
		temp_list = temp_list->next;
	return (temp_list);
}

void	free_list(t_swap *stack)
{
	t_swap	*temp;
	t_swap	*head;

	if (!stack)
		return ;
	head = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
		if (stack == head)
			break ;
	}
}

int	list_size(t_swap *stack)
{
	int		i;
	t_swap	*temp_list;

	if (!stack)
		return (0);
	i = 0;
	temp_list = stack;
	while (temp_list)
	{
		i++;
		if (temp_list->next == stack)
			break ;
		temp_list = temp_list->next;
	}
	return (i);
}
