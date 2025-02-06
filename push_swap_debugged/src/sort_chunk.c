#include "push_swap.h" 

void chunk_sort(t_push_swap *ps, int chunk_count)
{
    int chunk_size = ps->stack_a->size / chunk_count;

    for (int i = 0; i < chunk_count; i++)
    {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size;

        // Push numbers in the current chunk to stack_b
        for (int j = 0; j < ps->stack_a->size; j++)
        {
            if (ps->stack_a->top->index >= start && ps->stack_a->top->index < end)
                pb(ps);
            else
                ra(ps);
        }

        // Sort stack_b (can be descending for optimization)
        while (ps->stack_b->size > 0)
            pa(ps);
    }
}

