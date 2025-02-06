#include "push_swap.h"

void radix_sort(t_push_swap *ps)
{
    int max_bits = 0;
    int max_value = ps->stack_a->size - 1;
    int i = 0;
    int j = 0;
    // Find the maximum number of bits
    while ((max_value >> max_bits) != 0)
        max_bits++;

    while (i < max_bits)
    {
        int size = ps->stack_a->size;

        while (j < size)
        {
            int num = ps->stack_a->top->index;

            if (((num >> i) & 1) == 0)
                pb(ps);
            else
                ra(ps);
            j++;
        }

        // Move all elements back to stack_a
        while (ps->stack_b->size > 0)
            pa(ps);
        i++;    
    }
}

