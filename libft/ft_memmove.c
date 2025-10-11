/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:36 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:11:16 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*ing;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	str = (const unsigned char *)src;
	ing = (unsigned char *)dest;
	if (ing > str)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ing[i] = str[i];
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			ing[i] = str[i];
	}
	return (dest);
}
