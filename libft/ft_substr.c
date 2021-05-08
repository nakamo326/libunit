#include "libft.h"

char	*ft_substr(char const *input, unsigned int start, size_t substr_len)
{
	char	*substr;
	size_t	input_len;

	if (!input)
		return (NULL);
	input_len = ft_strlen(input);
	if (input_len <= start)
	{
		substr = malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		else
			substr[0] = '\0';
		return (substr);
	}
	if (input_len + 1 - start < substr_len)
		substr_len = input_len + 1 - start;
	substr = malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	input += start;
	ft_strlcpy(substr, input, substr_len + 1);
	return (substr);
}
