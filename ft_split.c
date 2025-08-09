/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absouman <absouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:04:51 by absouman          #+#    #+#             */
/*   Updated: 2025/08/07 13:53:09 by absouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*next_word(char const **s, char c, size_t *len)
{
	const char	*start;

	while (**s == c)
		(*s)++;
	start = *s;
	*len = 0;
	while (**s && **s != c)
	{
		(*len)++;
		(*s)++;
	}
	return ((char *)start);
}

static void	ft_free_all(char **lst, int last)
{
	while (--last >= 0)
		free(lst[last]);
	free(lst);
}

static int	fill_words(char **lst, char const *s, char c)
{
	int			i;
	size_t		word_len;
	const char	*word_start;

	i = 0;
	while (*s)
	{
		word_start = next_word(&s, c, &word_len);
		if (word_len > 0)
		{
			lst[i] = ft_substr(word_start, 0, word_len);
			if (!lst[i])
			{
				ft_free_all(lst, i);
				return (0);
			}
			i++;
		}
	}
	lst[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
		return (NULL);
	lst = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	if (!fill_words(lst, s, c))
		return (NULL);
	return (lst);
}
