#include "push_swap.h"

void radix_sort(t_push_swap *ps) {
    if (!ps || !ps->stack_a) return;

    int max_bits = 0;
    int max_index = ps->stack_a->size - 1;
    while (max_index > 0) {
        max_bits++;
        max_index >>= 1;
    }

    printf("Max bits: %d\n", max_bits);

    for (int i = 0; i < max_bits; i++) {
        int size = ps->stack_a->size;
        int count_zeros = 0;
        printf("--- Bit: %d ---\n", i);

        for (int j = 0; j < size; j++) {
            t_node *top_node = ps->stack_a->top;
            if (((top_node->index >> i) & 1) == 0) {
                pb(ps);
                count_zeros++;
            } else {
                ra(ps);
            }
        }

        while (count_zeros-- > 0) {
            pa(ps);
        }
        print_stack(ps->stack_a, "A after bit pass");
    }
}
