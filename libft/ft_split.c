#include "libft.h"

static void *ft_free(char **splitted, size_t i)
{
    while (i--)
        free(splitted[i]);
    free(splitted);
    return (NULL);
}

static size_t wordcounter(const char *s, char c)
{
    size_t wordcount;
    size_t i;

    wordcount = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            wordcount++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (wordcount);
}

static char	*wordextracter(const char *s, size_t *i, char c)
{
    size_t wordlen;  
    char *word;
    
    wordlen = 0;
    while (s[*i] && s[*i] == c)  
        (*i)++;
    while (s[*i + wordlen] && s[*i + wordlen] != c)  
        wordlen++;
    word = ft_substr(s, *i, wordlen);  
    *i += wordlen;  
    return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	wordcount;
	size_t	i = 0;
	size_t	j = 0;

	if (!s)
		return (NULL);

	wordcount = wordcounter(s, c);
	ret = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!ret)
		return (NULL);

	while (j < wordcount)
	{
		ret[j] = wordextracter(s, &i, c);
		if (!ret[j++])
			return (ft_free(ret, j - 1));
	}
	ret[j] = NULL;
	return (ret);
}
/*int main(void)
{
    char **result;
    int i;

    result = ft_split("He Truly Feels", ' ');
    if (!result)
        return (1);  
    
    i = 0;
    while (result[i])
    {
        ft_putstr_fd(result[i], 1);   
        i++;
    }
    return 0;
}*/