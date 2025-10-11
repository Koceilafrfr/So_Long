/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:12:36 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 15:59:25 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*ing;
	size_t			i;

	i = 0;
	str = (unsigned char *)s1;
	ing = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n - 1 > i)
	{
		if (str[i] != ing[i])
			return (str[i] - ing[i]);
		i++;
	}
	return (str[i] - ing[i]);
}
// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("abc", "abc", 7));
// 	printf("%d\n", memcmp("abc", "abc", 7));
// 	return (0);
// }