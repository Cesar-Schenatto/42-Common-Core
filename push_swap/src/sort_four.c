/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:34:12 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:13:36 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_push_swap *ps)
{
	if (!ps || !ps->stack_a || ps->stack_a->size != 4)
		return ;
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
}
