#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	joined_str_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	joined_str_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(joined_str_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, joined_str_len + 1);
	ft_strlcat(result, s2, joined_str_len + 1);
	return (result);
}
