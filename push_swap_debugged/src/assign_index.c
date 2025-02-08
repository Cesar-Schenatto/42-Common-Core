#include "push_swap.h"

// Helper function to duplicate an array
int	*duplicate_array(t_stack *stack)
{
	int		*array;
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current != NULL)
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}

// Helper function to sort an integer array (you can use qsort or implement your own)
int compare_integers(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Assign indexes to nodes in stack based on their values' sorted position.
void assign_indexes(t_stack *stack) 
{
    if (!stack || stack->size == 0) return;

    int *sorted_values = duplicate_array(stack);
    if (!sorted_values) return; // Handle malloc error if needed

    qsort(sorted_values, stack->size, sizeof(int), compare_integers);

    t_node *current = stack->top;
    int i = 0;
    while (current) {
        // Find the index of current->value in sorted_values
        for (i = 0; i < stack->size; i++) {
            if (current->value == sorted_values[i]) {
                current->index = i;
                break; // Found the index, move to next node
            }
        }
        current = current->next;
    }
    free(sorted_values);
}
