#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size > dstlen)
	{
		i = 0;
		while (i < size - dstlen - 1 && i <= srclen)
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		return (dstlen + srclen);
	}
	return (size + srclen);
}
