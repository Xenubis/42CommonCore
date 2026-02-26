#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		r;
	int		len;
	char	c;
	char	str[50000];

	if (ac != 2)
		return (1);
	r = read(0, &c, 1);
	if (r == -1)
		perror("read : ");
	i = 0;
	while (r)
	{
		str[i] = c;
		r = read(0, &c, 1);
		i++;
	}
	len = strlen(av[1]);
	i = 0;
	while (str[i])
	{
		if (strncmp(av[1], &str[i], len) == 0)
		{
			j = 0;
			while (j < len)
			{
				printf("*");
				i++;
				j++;
			}
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
	return (0);
}
