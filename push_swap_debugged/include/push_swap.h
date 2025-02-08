/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:34:56 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/06 15:24:52 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* Node structure */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* Stack structure */
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Main program structure */
typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push_swap;

/* Node functions */
t_node		*create_node(int value);
void		free_node(t_node *node);

/* Stack functions */
t_stack		*init_stack(void);
void		push(t_stack *stack, t_node *node);
t_node		*pop(t_stack *stack);
int			stack_size(t_stack *stack);

/* Main functions */
t_push_swap	*init_push_swap(void);
void assign_indexes(t_stack *stack);

/* Free functions */
void	*ft_free(char **splitted, size_t i);
void	free_stack(t_stack *stack);
void free_push_swap(t_push_swap *ps);

/* String functions */
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		*ft_free(char **splitted, size_t i);
size_t		ft_strlen(const char *s);

/* Utility functions */
int			is_valid_integer(const char *str);
int			is_sorted(t_stack *stack);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
int			ft_atoi(const char *s);

/* Operators */
/* Push */
void		pa(t_push_swap *ps);
void		pb(t_push_swap *ps);

/* Swap */
void		sa(t_push_swap *ps);
void		sb(t_push_swap *ps);
void		ss(t_push_swap *ps);
void		swap(t_stack *stack);

/* Rotate */
void		rotate(t_stack *stack);
void		ra(t_push_swap *ps);
void		rb(t_push_swap *ps);
void		rr(t_push_swap *ps);

/* Reverse */
void		reverse_rotate(t_stack *stack);
void		rra(t_push_swap *ps);
void		rrb(t_push_swap *ps);
void		rrr(t_push_swap *ps);

/* Error Handling functions */
int			has_duplicates(t_stack *stack);
int			validate_stack(t_stack *stack_a);

/* Parsing */
int			parse_values(char *str, t_stack *stack_a);
int			parse_input(int argc, char **argv, t_stack *stack_a);

/* Sort algorithms */
void		sort_three(t_push_swap *ps);
void        sort_four(t_push_swap *ps);
void		sort_five(t_push_swap *ps);
void		radix_sort(t_push_swap *ps);
void        assign_indexes(t_stack *stack);
void		push_min_to_b(t_push_swap *ps);
int         find_index(int *sorted_arr, int size, int value);

/* Debugging */
void		print_stack(t_stack *stack, const char *name);

#endif
