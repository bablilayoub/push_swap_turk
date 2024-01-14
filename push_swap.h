/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:47:44 by abablil           #+#    #+#             */
/*   Updated: 2024/01/14 01:17:50 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

// Swap struct
typedef struct s_swap
{
	int				value;
	int				index;
	struct s_swap	*next;
	struct s_swap	*prev;
	struct s_swap	*target;
	int				push_cost;
	int				above_median;
}	t_swap;

// Indexing
void	set_index(t_swap *stack);

// List utils
int		get_min_index(t_swap *stack);
int		is_sorted(t_swap **stack);
t_swap	*get_last_list(t_swap *list);
void	free_list(t_swap *stack);

// Utils
void	free_args(char **args);
void	send_error(void);

// List
t_swap	*new_list(int value);
void	push_front(t_swap **stack, t_swap *new_node);
void	push_back(t_swap **stack, t_swap *new_node);
int		list_size(t_swap *stack);
int		get_min_value(t_swap *stack);
int		get_max_value(t_swap *stack);

// More operations
void	rotate_a(t_swap **stack_a);
void	rotate_b(t_swap **stack_b);
void	rotate_a_and_b(t_swap **stack_a, t_swap **stack_b);
void	reverse_rotate_a(t_swap **stack_a);
void	reverse_rotate_b(t_swap **stack_b);

// Operations
void	swap_a(t_swap **stack_a);
void	swap_b(t_swap **stack_b);
void	swap_a_and_b(t_swap **stack_a, t_swap **stack_b);
void	push_a(t_swap **stack_a, t_swap **stack_b);
void	push_b(t_swap **stack_a, t_swap **stack_b);
void	prepare_stack(t_swap **stack_a, char **args);

// Parse args
char	**handle_args(char **args);

// Start sorting
void	start_sorting(t_swap **stack_a, t_swap **stack_b);
void	sort_stack(t_swap **stack_a, t_swap **stack_b);

// Stack
void	swap(t_swap **stack);
void	push(t_swap **stack_a, t_swap **stack_b);
void	rotate(t_swap **stack);
void	reverse_rotate(t_swap **stack);

// Utils
int		next_min_value(t_swap *stack, int min_value);
void	free_args(char **args);
void	send_error(void);
char	*convert_args(char **args);
void	print_stack(t_swap *stack);

// Targets
t_swap	*get_min_target(t_swap *stack);
t_swap	*get_max_target(t_swap *stack);
int		get_median(t_swap *stack);
void	set_targets(t_swap **stack_a, t_swap **stack_b, int found_target);

// Cost
void	set_cost(t_swap **stack_a, t_swap **stack_b);

#endif