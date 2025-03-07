/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:04:03 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:48:36 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*current;

	printf ("Stack %s: ", name);
	current = stack->top;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf ("\n");
}

int	handle_errors(int ac, char **av, t_push_swap *ps)
{
	if (parse_input(ac, av, ps->stack_a) || has_duplicates(ps->stack_a))
	{
		free_push_swap(ps);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(ps->stack_a))
	{
		free_push_swap(ps);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return (0);
	ps = init_push_swap();
	if (!ps || handle_errors(ac, av, ps))
		return (1);
	assign_indexes(ps->stack_a);
	if (ps->stack_a->size == 2)
		return (ra(ps), free_push_swap(ps), 0);
	if (ps->stack_a->size == 3)
		sort_three(ps);
	else if (ps->stack_a->size == 4)
		sort_four(ps);
	else if (ps->stack_a->size == 5)
		sort_five(ps);
	else
		radix_sort(ps);
	free_push_swap(ps);
	return (0);
}
