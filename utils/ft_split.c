/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:28:42 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/17 02:58:31 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_words(const char *s, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == sep)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *start, char sep)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (start[len] && start[len] != sep)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = start[i];
	word[i] = '\0';
	return (word);
}

static void	*free_words(char **words, int i)
{
	while (i--)
		free(words[i]);
	free(words);
	return (NULL);
}

static const char	*skip_sep(const char *s, char sep)
{
	while (*s && *s == sep)
		s++;
	return (s);
}

char	**ft_split(const char *s, char sep)
{
	int		i;
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (count_words(s, sep) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		s = skip_sep(s, sep);
		if (*s)
		{
			words[i] = copy_word(s, sep);
			if (!words[i])
				return (free_words(words, i));
			i++;
			while (*s && *s != sep)
				s++;
		}
	}
	words[i] = NULL;
	return (words);
}
