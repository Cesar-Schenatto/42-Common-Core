/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:39:26 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:39:43 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->stack_a = init_stack();
	ps->stack_b = init_stack();
	if (!ps->stack_a || !ps->stack_b)
	{
		free_push_swap(ps);
		return (NULL);
	}
	return (ps);
}
