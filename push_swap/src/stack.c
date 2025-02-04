#include "push_swap.h"

// Initialize an empty stack
t_stack *init_stack(void)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

// Push a node onto the stack
void push(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Pop a node from the stack
t_node *pop(t_stack *stack)
{
    if (!stack || stack->size == 0)
        return (NULL);
    t_node *top_node = stack->top;
    stack->top = top_node->next;
    top_node->next = NULL;
    stack->size--;
    return (top_node);
}

// Return stack size
int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;  // Start from the top node of the stack

    while (current)
    {
        size++;
        current = current->next;  // Move to the next node
    }
    return (size);
}
