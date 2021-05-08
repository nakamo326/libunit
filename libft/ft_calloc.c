#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	calloc_size;
	void	*p_res;

	if (size == 0 || nmemb == 0)
	{
		p_res = malloc(1);
		ft_bzero(p_res, 1);
		return (p_res);
	}
	if (size > ((size_t) - 1) / nmemb)
		return (NULL);
	calloc_size = nmemb * size;
	p_res = malloc(calloc_size);
	if (!p_res)
		return (NULL);
	ft_bzero(p_res, calloc_size);
	return (p_res);
}
