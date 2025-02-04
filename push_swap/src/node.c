#include "push_swap.h" 

// Create a new node
t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = -1;  // Initialize to -1 (unset)
    new_node->next = NULL;
    return (new_node);
}

// Free a single node
void free_node(t_node *node)
{
    if (node)
        free(node);
}


