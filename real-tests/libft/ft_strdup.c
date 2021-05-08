#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	str_len;

	str_len = ft_strlen(str);
	result = malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str, sizeof(char) * (str_len + 1));
	return (result);
}
