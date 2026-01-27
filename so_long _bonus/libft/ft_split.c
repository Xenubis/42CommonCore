/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:43:46 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/13 17:59:59 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (word);
}

static char	*ft_wordup(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc((sizeof(char)) * (i + 1));
	if (!word)
		return (word = NULL, NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_words(char **str, int i)
{
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}

char	**ft_split(char const *str, char c)
{
	int		j;
	char	**strs;

	j = 0;
	if (!str)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!strs || !str)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			strs[j] = ft_wordup(str, c);
			if (!strs[j])
				return (free_words(strs, j), NULL);
			while (*str && *str != c)
				str++;
			j++;
		}
		else
			str++;
	}
	strs[j] = NULL;
	return (strs);
}
