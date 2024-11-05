#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t j;

    if (!s1 || !set)
        return(NULL);
    i = 0;
    while (s1[i] && ft_strchr(set, s1[i]))
        i++;
    j = ft_strlen(s1);
    while (j > i && ft_strchr(set, s1[j - 1]))
        j--;
    if (i == j)
        return (ft_strdup(""));
    return (ft_substr(s1, i, j - i));
}

/*int main (void)
{
    char buffer[] = "And Did it My waaaaayA";
    ft_putendl_fd(ft_strtrim(buffer, "A"), 1);
    return 0;
}*/