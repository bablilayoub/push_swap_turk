/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:38:27 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 01:46:31 by abablil          ###   ########.fr       */
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
