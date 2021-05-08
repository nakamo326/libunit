#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	trim_start;
	size_t	trim_end;
	size_t	result_len;

	if (!s1 || !set)
		return (NULL);
	trim_start = 0;
	trim_end = (int) ft_strlen(s1);
	while ((ft_strchr(set, (int) s1[trim_start])) && (trim_start < trim_end))
		trim_start++;
	if (trim_start == trim_end)
	{
		result = ft_strdup("");
		return (result);
	}
	while (ft_strchr(set, (int) s1[trim_end]))
		trim_end--;
	result_len = trim_end - trim_start + 1;
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + trim_start, result_len + 1);
	return (result);
}
