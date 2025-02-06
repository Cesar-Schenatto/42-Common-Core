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
