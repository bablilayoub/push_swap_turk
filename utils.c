/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:12:01 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 01:21:44 by abablil          ###   ########.fr       */
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

char	*convert_args(char **args)
{
	char		*temp;
	char		*result;
	static int	i = 0;

	result = ft_strdup("");
	if (!result)
		send_error();
	while (args[++i])
	{
		temp = result;
		result = ft_strjoin(result, args[i]);
		if (!result)
		{
			free(temp);
			send_error();
		}
		temp = result;
		result = ft_strjoin(result, " ");
		if (!result)
		{
			free(temp);
			send_error();
		}
	}
	return (result);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args || !*args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	send_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	print_stack(t_swap *stack)
{
	t_swap	*temp;
	int		target_value;
	int		cost;
	
	temp = stack;
	while (temp)
	{
		target_value = temp->target ? temp->target->value : 0;
		cost = temp->push_cost ? temp->push_cost : 0;
		ft_printf("Value: %d, Index: %d, Above median: %d, Target Value %d, Push cost : %d\n",
			temp->value, temp->index, temp->above_median, target_value, cost);
		temp = temp->next;
	}
}