#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}

/*int main (void)
{
    char buffer[] = "The record shows ";
    char buffer2[] = "I took the blows";
    ft_putstr_fd(ft_strjoin(buffer, buffer2), 1);
    return 0;
}*/