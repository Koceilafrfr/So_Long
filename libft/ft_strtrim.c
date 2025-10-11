/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:33:09 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 16:04:11 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen((char *)s1);
	while (s1[start] && is_in_set(set, s1[start]))
		start++;
	while (end > start && is_in_set(set, s1[end - 1]))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
// int	main (void)
// {
// 	//char	str[]= "MiqYanisdad";
// 	//char	ing[]= "Miqdad";
// 	printf("%s\n", ft_strtrim("   xxxtripouille", " x"));
// 	return (0);
// }