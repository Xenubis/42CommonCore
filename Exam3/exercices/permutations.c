#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	reverse(char *str, int start, int end)
{
	while (start < end)
	{
		swap(&str[start], &str[end]);
		start++;
		end--;
	}
}

void	sort(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

int	next_permutation(char *str, int len)
{
	int	i;
	int	j;

	i = len - 2;
	while (i >= 0 && str[i] >= str[i + 1])
		i--;
	if (i < 0)
		return (0);
	j = len - 1;
	while (str[j] <= str[i])
		j--;
	swap(&str[i], &str[j]);
	reverse(str, i + 1, len - 1);
	return (1);
}

int	main(int ac, char **av)
{
	char	*permu;
	int		len;
	int		i;

	if (ac != 2)
		return (0);
	len = ft_strlen(av[1]);
	permu = malloc(len + 1);
	if (!permu)
		return (1);
	i = 0;
	while (i <= len)
	{
		permu[i] = av[1][i];
		i++;
	}
	sort(permu, len);
	puts(permu);
	while (next_permutation(permu, len))
		puts(permu);
	free(permu);
	return (0);
}
