/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:16 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:03:46 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*ing;
	size_t	i;
	size_t	j;

	str = (char *)big;
	ing = (char *)little;
	i = 0;
	if (ing[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == ing[j] && (i + j) < len && str[i + j])
			j++;
		if (ing[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("oh no not the empty string !", "", 0));
// 	printf("%s\n", strnstr("oh no not the empty string !", "", 0));
// 	return (0);
// NE PAS OUBLIER ing == NULL ||
// }