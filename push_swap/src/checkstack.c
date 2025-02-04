#include "push_swap.h" 

// Helper function to check duplicates
int has_duplicates(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        t_node *runner = current->next;
        while (runner)
        {
            if (current->value == runner->value)
                return (1);  // Duplicate found
            runner = runner->next;
        }
        current = current->next;
    }
    return (0);
}

// Validate the stack
int validate_stack(t_stack *stack_a)
{
    if (!stack_a || stack_a->size == 0)
        return (1);  // Empty stack is invalid
    if (has_duplicates(stack_a))
        return (1);  // Duplicates are not allowed
    return (0);  // Stack is valid
}
