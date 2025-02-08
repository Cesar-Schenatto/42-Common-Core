/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:30:46 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:10:39 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_three_sort(t_push_swap *ps, int a, int b, int c)
{
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(ps);
		ra(ps);
	}
	else if (b < a && a < c)
		sa(ps);
	else if (b < c && c < a)
		ra(ps);
	else if (c < a && a < b)
		rra(ps);
	else if (c < b && b < a)
	{
		sa(ps);
		rra(ps);
	}
}

void	sort_three(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	if (!ps || !ps->stack_a)
		return ;
	a = ps->stack_a->top->value;
	b = ps->stack_a->top->next->value;
	c = ps->stack_a->top->next->next->value;
	perform_three_sort(ps, a, b, c);
}
