#include "push_swap.h"

int parse_values(char *str, t_stack *stack_a)
{
    char **values = ft_split(str, ' ');
    if (!values)
        return (1);

    // Count the number of values
    int count = 0;
    while (values[count])
        count++;

    // Push values onto the stack in reverse order
    for (int i = count - 1; i >= 0; i++)
    {
        printf("Parsing value: %s\n", values[i]);  // Debug print
        if (!is_valid_integer(values[i]))
        {
            printf("Invalid integer: %s\n", values[i]);  // Debug print
            ft_free(values, count);
            return (1);
        }
        int value = ft_atoi(values[i]);
        if (value == 0 && values[i][0] != '0')  // Check for overflow
        {
            printf("Overflow detected: %s\n", values[i]);  // Debug print
            ft_free(values, count);
            return (1);
        }
        printf("Converted value: %d\n", value);  // Debug print
        t_node *new_node = create_node(value);
        if (!new_node)
        {
            ft_free(values, count);
            return (1);
        }
        push(stack_a, new_node);
        print_stack(stack_a, "A");  // Debug print to verify stack state
    }

    ft_free(values, 0);
    return (0);
}

int parse_input(int ac, char **av, t_stack *stack)
{
    if (ac < 2 || !stack)
        return (1);  // Error: Invalid input

    // Process arguments from the first to the last
    int i = 1;
    while (i < ac)
    {
        printf("Processing argument: %s\n", av[i]);  // Debug print
        if (av[i][0] == '"' || av[i][0] == '\'')  // Handle quoted arguments
        {
            // Remove quotes and parse the string
            char *str = av[i] + 1;  // Skip the opening quote
            size_t len = ft_strlen(str);
            if (len > 0 && str[len - 1] == '"')  // Check for closing quote
                str[len - 1] = '\0';  // Remove the closing quote
            printf("Quoted argument after removing quotes: %s\n", str);  // Debug print
            if (parse_values(str, stack))
                return (1);  // Error: Invalid input
        }
        else
        {
            if (parse_values(av[i], stack))
                return (1);  // Error: Invalid input
        }
        i++;
    }

    return (0);  // Success
}
