#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	index;
	size_t	num_of_words;

	index = 0;
	num_of_words = 0;
	if (s[0] == '\0')
		return (0);
	while (s[index] == c)
		index++;
	if (index == 0)
		index++;
	while (s[index] != '\0')
	{
		if ((s[index] == c && s[index + 1] != c)
			|| (s[index] != c && s[index + 1] == '\0'))
		{
			num_of_words++;
		}
		index++;
	}
	return (num_of_words);
}

static size_t	ft_get_split_end(char const *s, char c, int start)
{
	size_t	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	ft_split_free(char **result, int free_num)
{
	int	i;

	i = 0;
	while (i < free_num)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	ft_split_exec(char **result, char const *s, char c, size_t len)
{
	size_t	idx;
	size_t	word_len;
	size_t	split_start;

	idx = 0;
	split_start = 0;
	while (idx < len)
	{
		word_len = ft_get_split_end(s, c, split_start) - split_start;
		if (word_len == 0)
		{
			split_start++;
			continue ;
		}
		result[idx] = malloc(word_len + 1);
		if (result[idx] == NULL)
		{
			ft_split_free(result, idx + 1);
			return (0);
		}
		ft_strlcpy(result[idx], &s[split_start], word_len + 1);
		split_start += word_len + 1;
		idx++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_of_words;
	char	**result;

	if (!s)
		return (NULL);
	num_of_words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (num_of_words + 1));
	if (!result)
		return (NULL);
	if (!ft_split_exec(result, s, c, num_of_words))
		return (NULL);
	result[num_of_words] = NULL;
	return (result);
}
