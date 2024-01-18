/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:06:15 by abablil           #+#    #+#             */
/*   Updated: 2024/01/18 02:09:02 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_swap *stack_a, char **args, int value)
{
	t_swap	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->value == value)
		{
			free_args(args);
			free_list(stack_a);
			send_error();
		}
		temp = temp->next;
	}
}

void	found_sign_and_skip_zeros(char *number, size_t *i, int *sign)
{
	int	found_zero;

	found_zero = 0;
	if (!number[*i])
		return ;
	if (number[*i] == '-' || number[*i] == '+')
	{
		if (number[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (number[*i] == '0')
	{
		found_zero = 1;
		(*i)++;
	}
	if (found_zero && number[*i] == '\0')
		(*i)--;
}

int	is_valid_number(char *number)
{
	size_t		i;
	long long	result;
	int			sign;
	int			len;

	i = 0;
	result = 0;
	sign = 1;
	len = 0;
	found_sign_and_skip_zeros(number, &i, &sign);
	if (!number[i])
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		result = result * 10 + (number[i] - '0');
		i++;
		len++;
	}
	result *= sign;
	if (ft_strlen(number) != i || result < INT_MIN
		|| result > INT_MAX || len > 10)
		return (0);
	return (1);
}

char	**handle_args(char **args)
{
	char	*temp;
	int		i;

	i = 0;
	temp = convert_args(args);
	if (!temp)
		send_error();
	args = ft_split(temp, ' ');
	free(temp);
	if (!args)
		send_error();
	while (args[i])
	{
		if (!is_valid_number(args[i]) || !args[i][0])
		{
			free_args(args);
			send_error();
		}
		i++;
	}
	return (args);
}

void	prepare_stack(t_swap **stack_a, char **args)
{
	t_swap	*new_node;
	int		i;

	i = 0;
	while (args[i])
	{
		check_duplicates(*stack_a, args, ft_atoi(args[i]));
		new_node = new_list(ft_atoi(args[i]));
		if (!new_node)
		{
			free_args(args);
			free_list(*stack_a);
			send_error();
		}
		new_node->index = -1;
		new_node->index_value = -1;
		push_back(stack_a, new_node);
		i++;
	}
	if (args)
		free_args(args);
	set_index(*stack_a);
	set_index_value(*stack_a);
}
