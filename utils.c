/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:12:01 by abablil           #+#    #+#             */
/*   Updated: 2024/01/16 20:31:15 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*check_if_valid_number(char *result, char *number)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]))
			found_digit = 1;
		i++;
	}
	if (!found_digit)
	{
		free(result);
		send_error();
	}
	return (number);
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
		result = ft_strjoin(result, check_if_valid_number(result, args[i]));
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
	char	*above_median_str;
	char	*target_value_str;

	temp = stack;
	above_median_str = "Above median: ";
	target_value_str = "Target Value: ";
	while (temp)
	{
		if (temp->target)
			target_value = temp->target->value;
		else
			target_value = 0;
		if (temp->push_cost)
			cost = temp->push_cost;
		else
			cost = 0;
		ft_printf("Value: %d, Index: %d, %s%d, %s%d, Push cost : %d\n",
			temp->value, temp->index, above_median_str, temp->above_median,
			target_value_str, target_value, cost);
		temp = temp->next;
	}
}
