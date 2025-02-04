#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return (1); // An empty stack is considered sorted

    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0); // Not sorted
        current = current->next;
    }
    return (1); // Sorted
}

int find_min(t_stack *stack)
{
    t_node *current;
    int min;

    if (!stack || !stack->top)
        return (0); // Return 0 if the stack is empty

    current = stack->top;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int find_max(t_stack *stack)
{
    t_node *current;
    int max;

    if (!stack || !stack->top)
        return (0); // Return 0 if the stack is empty

    current = stack->top;
    max = current->value;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int	ft_atoi(const char *s)
{
	int	i;
	long	r;
	int	f;

	i = 0;
	r = 0;
	f = 1;
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			f *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		if ((f == 1 && r > 2147483647) || (f == -1 && -r < -2147483648))
			return (0);  // Overflow
		i++;
	}
	return (f * r);
}


int is_valid_integer(const char *str)
{
    if (!str || *str == '\0')
        return 0;  // Empty string is invalid

    int sign = 1;
    long result = 0;

    // Handle optional sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Convert string to long and check for overflow
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;  // Non-digit character found

        result = result * 10 + (*str - '0');

        // Check for overflow
        if ((sign == 1 && result > 2147483647) || (sign == -1 && -result < -2147483648))
            return 0;

        str++;
    }

    return 1;  // Valid integer
}
