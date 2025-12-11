/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:16:33 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/11 14:01:30 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	count_word(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
				i++;
		}
	}
	return (count);
}

char	*ft_wordup(char *str)
{
	int	i;
	int len;
	char *word;

	len = 0;
	while (str[len] && str[len] != ' ' && str[len] != '\n' && str[len] != '\t')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int	i;
	char **strs;

	i = 0;
	if (!str)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_word(str) + 1));
	if (!strs)
		return (NULL);
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		if (*str != ' ' && *str != '\n' && *str != '\t')
		{
			strs[i] = ft_wordup(str);
			if (!strs[i])
				return (NULL);
			i++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	strs[i] = NULL;
	return (strs);
}

int main(void)
{
    char    *str = "  Salut\tles amis\ncomment ça va ?  ";
    char    **tab = ft_split(str);
    int     i = 0;

    if (!tab)
    {
        printf("Erreur d'allocation\n");
        return (1);
    }

    while (tab[i])
    {
        printf("mot[%d] = \"%s\"\n", i, tab[i]);
        free(tab[i]);
        i++;
    }
    free(tab);

    return (0);
}