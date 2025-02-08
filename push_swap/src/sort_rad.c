/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:37:31 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:25:12 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	max_index = stack->size - 1;
	max_bits = 0;
	while (max_index > 0)
	{
		max_bits++;
		max_index >>= 1;
	}
	return (max_bits);
}

static void	process_radix_bit(t_push_swap *ps, int bit)
{
	int		size;
	int		count_zeros;
	int		j;
	t_node	*top;

	size = ps->stack_a->size;
	count_zeros = 0;
	j = 0;
	while (j < size)
	{
		top = ps->stack_a->top;
		if ((((top->index) >> bit) & 1) == 0)
		{
			pb(ps);
			count_zeros++;
		}
		else
			ra(ps);
		j++;
	}
	j = 0;
	while (j++ < count_zeros)
		pa(ps);
}

void	radix_sort(t_push_swap *ps)
{
	int	max_bits;
	int	bit;

	if (!ps || !ps->stack_a)
		return ;
	max_bits = get_max_bits(ps->stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		process_radix_bit(ps, bit);
		bit++;
	}
}
