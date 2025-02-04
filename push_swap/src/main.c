#include "push_swap.h"

void print_stack(t_stack *stack, const char *name)
{
    printf("Stack %s: ", name);
    t_node *current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);  // No parameters, return silently

    t_push_swap *ps = init_push_swap();  // Initialize the program
    if (!ps)
        return (1);  // Error: Failed to initialize

    // Parse input arguments into stack_a
    if (parse_input(ac, av, ps->stack_a))
    {
        free_push_swap(ps);  // Free memory on error
        write(2, "Error\n", 6);  // Print error message
        return (1);
    }

    // Print stack_a after parsing
    print_stack(ps->stack_a, "A");

    // Check for duplicates in stack_a
    if (has_duplicates(ps->stack_a))
    {
        free_push_swap(ps);  // Free memory on error
        write(2, "Error\n", 6);  // Print error message
        return (1);
    }

    // If the stack is already sorted, exit
    if (is_sorted(ps->stack_a))
    {
        free_push_swap(ps);  // Free memory
        return (0);
    }

    // Call the appropriate sorting algorithm based on stack size
    if (ps->stack_a->size == 3)
        sort_three(ps);  // Sort 3 elements
    else if (ps->stack_a->size == 5)
        sort_five(ps);  // Sort 5 elements
    else
        radix_sort(ps);  // Use radix sort for larger stacks

    // Print stack_a after sorting
    print_stack(ps->stack_a, "A");

    // Free memory and exit
    free_push_swap(ps);
    return (0);
}
