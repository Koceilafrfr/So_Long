/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:32:16 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/15 15:29:08 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	sizesrc;
	size_t	i;

	i = 0;
	sizesrc = ft_strlen((char *)src);
	if (siz != 0)
	{
		while (src[i] && i < (siz - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (sizesrc);
}
// if (!src || !dest)
// 	return (0);