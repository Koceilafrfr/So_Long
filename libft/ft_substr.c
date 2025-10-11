/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:17:54 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:04:53 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_chaine_vide(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			real_len;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_chaine_vide());
	real_len = 0;
	while (real_len < len && s[start + real_len])
		real_len++;
	str = malloc(sizeof(char) * (real_len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int	main(void)
// {
// 	printf("%s\n", ft_substr("hola", 4294967295, 18446744073709551615));
// 	return (0);
// }