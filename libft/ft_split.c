/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:43:15 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 15:57:38 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			i += word_len(&s[i], c);
		}
	}
	return (count);
}

// size_t	count_word(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = -1;
// 	count = 0;
// 	while (s[++i])
// 		if (s[i] == c)
// 			count++;
// 	return (count);
// }

char	*dup_split(char const *s, char c)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (word_len(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[j++] = dup_split(&s[i], c);
			if (!tab[j - 1])
				return (free_tab(tab), NULL);
			i += word_len(&s[i], c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
/*int	main()
{
	char **tab = ft_split("YanisaMaximeaoufasboaaaaaaeuh", 'a');
	for (int i = 0; tab[i]; i++)
	{
		printf("%s\n", tab[i]);
	}
	return (0);
}*/
// int	main(void)
// {
// 	 char	*str = "   lorem   ipsum dolor     sit amet,
// consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
// 	 char	sep = ' ';
// 	char	**split = NULL;
// 	size_t	i = 0;

// 	split = ft_split(str, sep);

// 	if (!split)
// 	return (1);
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return (0);
// }
