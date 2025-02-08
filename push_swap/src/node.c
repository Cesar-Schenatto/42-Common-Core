/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:32:22 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:39:03 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	free_node(t_node *node)
{
	if (node)
		free(node);
}
