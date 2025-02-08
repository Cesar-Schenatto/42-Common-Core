/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:43:49 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:27:35 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*duplicate_array(t_stack *stack)
{
	int		*array;
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
	return (array);
}

static void	bubble_sort(int *arr, int size)
{
	int	sorted;
	int	tmp;
	int	i;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	assign_indexes(t_stack *stack)
{
	int		i;
	int		*sorted_values;
	t_node	*current;

	if (!stack || stack->size == 0)
		return ;
	sorted_values = duplicate_array(stack);
	if (!sorted_values)
		return ;
	bubble_sort(sorted_values, stack->size);
	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == sorted_values[i])
				break ;
			i++;
		}
		current->index = i;
		current = current->next;
	}
	free(sorted_values);
}
