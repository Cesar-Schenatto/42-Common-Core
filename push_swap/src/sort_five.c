#include "push_swap.h"

void push_min_to_b(t_push_swap *ps)
{
    if (!ps || !ps->stack_a || !ps->stack_b || ps->stack_a->size == 0)
        return;

    // Find the minimum value in stack_a
    t_node *current = ps->stack_a->top;
    t_node *min_node = current;
    int min_index = 0;
    int current_index = 0;
    int i = 0;

    while (current)
    {
        if (current->value < min_node->value)
        {
            min_node = current;
            min_index = current_index;
        }
        current = current->next;
        current_index++;
    }

    // Calculate the number of rotations needed
    int rotations = min_index;
    int direction = 1; // 1 for ra, -1 for rra

    if (rotations > ps->stack_a->size / 2)
    {
        rotations = ps->stack_a->size - rotations;
        direction = -1; // Use rra
    }

    // Rotate stack_a to bring min_node to the top
    while (i < rotations)
    {
        if (direction == 1)
            ra(ps); // Rotate forward
        else
            rra(ps); // Rotate backward
        i++;
    }

    // Push the min_node to stack_b
    pb(ps);
}

void sort_five(t_push_swap *ps)
{
    if (!ps || ps->stack_a->size > 5)
        return;

    // Push two smallest elements to stack_b
    push_min_to_b(ps);
    push_min_to_b(ps);

    // Sort remaining three elements in stack_a
    sort_three(ps);

    // Push back the smallest elements from stack_b
    pa(ps);
    pa(ps);
}
