/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:22:59 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:05:21 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*str;
	unsigned char	*ing;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	str = (const char *)src;
	ing = (unsigned char *)dest;
	while (i < n)
	{
		ing[i] = str[i];
		i++;
	}
	return (dest);
}
