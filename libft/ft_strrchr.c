/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:47:25 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:03:51 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == ((char)c))
		return ((char *)&s[i]);
	return (NULL);
}
/*int	main(void)
{
	printf("%s\n", ft_strrchr("yaanis", 'a'));
	printf("%s\n", strrchr("yaanis", 'a'));
	return (0);
	NE PAS OUBLIER if (s == NULL)
		return (NULL);
}*/