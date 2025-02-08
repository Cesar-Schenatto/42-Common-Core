#include "push_swap.h"

void sort_three(t_push_swap *ps)
{
    if (!ps || !ps->stack_a)
        return;
    printf("sort_three: size = %d, a=%d, b=%d, c=%d\n", ps->stack_a->size,
       ps->stack_a->top->value,
       ps->stack_a->top->next->value,
       ps->stack_a->top->next->next->value);
    int a = ps->stack_a->top->value;
    int b = ps->stack_a->top->next->value;
    int c = ps->stack_a->top->next->next->value;

//    printf("Before sorting: a = %d, b = %d, c = %d\n", a, b, c);  // Debug print

    if (a < b && b < c)         // Case 1: a < b < c (already sorted)
        return;                 // Do nothing
    else if (a < c && c < b)    // Case 2: a < c < b
    {
  //      printf("Case 2: a < c < b\n");
        sa(ps);                 // Swap a and b
        ra(ps);                 // Rotate
    }
    else if (b < a && a < c)    // Case 3: b < a < c
    {
   //     printf("Case 3: b < a < c\n");
        sa(ps);                 // Swap a and b
    }
    else if (b < c && c < a)    // Case 4: b < c < a
    {
   //     printf("Case 4: b < c < a\n");
        ra(ps);                 // Rotate
    }
    else if (c < a && a < b)    // Case 5: c < a < b
    {
    //    printf("Case 5: c < a < b\n");
        rra(ps);                // Reverse rotate
    }
    else if (c < b && b < a)    // Case 6: c < b < a
    {
    //    printf("Case 6: c < b < a\n");
        sa(ps);                 // Swap a and b
        rra(ps);                // Reverse rotate
    }
}
