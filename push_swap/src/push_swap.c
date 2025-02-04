#include "push_swap.h"

// Initialize the push_swap program
t_push_swap *init_push_swap(void)
{
    t_push_swap *ps = (t_push_swap *)malloc(sizeof(t_push_swap));
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

// Free the push_swap program
void free_push_swap(t_push_swap *ps)
{
    if (!ps)
        return;
    if (ps->stack_a)
    {
        while (ps->stack_a->size > 0)
            free_node(pop(ps->stack_a));
        free(ps->stack_a);
    }
    if (ps->stack_b)
    {
        while (ps->stack_b->size > 0)
            free_node(pop(ps->stack_b));
        free(ps->stack_b);
    }
    free(ps);
}

