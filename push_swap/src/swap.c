#include "push_swap.h"

// Swap the first two elements of a stack
void swap(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *first = stack->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack->top = second;
}

// Swap the first two elements of stack_a
void sa(t_push_swap *ps)
{
    if (ps)
    {
        swap(ps->stack_a);
        write(1, "sa\n", 3);
    }
}

// Swap the first two elements of stack_b
void sb(t_push_swap *ps)
{
    if (ps)
    {
        swap(ps->stack_b);
        write(1, "sa\n", 3);
    }
}

// Swap both stack_a and stack_b
void ss(t_push_swap *ps)
{
    if (ps)
    {
        swap(ps->stack_a);
        swap(ps->stack_b);
        write(1, "ss\n", 3);
    }
}

