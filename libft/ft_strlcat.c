/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:02:58 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:03:11 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	size_t	sizesrc;
	size_t	sizedest;
	size_t	i;
	size_t	sizefin;

	sizesrc = ft_strlen(src);
	sizedest = ft_strlen((const char *)dest);
	sizefin = sizesrc + sizedest;
	i = 0;
	if (sizedest >= siz)
		return (sizesrc + siz);
	while (src[i] && sizedest < siz - 1)
	{
		dest[sizedest] = src[i];
		i++;
		sizedest++;
	}
	dest[sizedest] = '\0';
	return (sizefin);
}

	/*int	main(void)
	{
		char dest[14] = "a";
		printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));\
		printf("%s\n", dest);
		char destv[14] = "a";
		printf("%zu\n", strlcat(destv, "lorem ipsum dolor sit amet", 15));
		printf("%s\n", destv);
		return (0);
		}*/
// if (siz <= sizesrc)
// 	return (sizesrc + siz);