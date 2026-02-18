int		puts(const char *str);

int	is_balanced(char *str)
{
	int	excess_open;
	int	i;

	i = 0;
	excess_open = 0;
	while (str[i])
	{
		if (str[i] == '(')
			excess_open++;
		else if (str[i] == ')' && --excess_open < 0)
			return (0);
		i++;
	}
	return (!excess_open);
}

void	solve(char *str, int pos, int rem_open, int rem_close)
{
	if (!rem_close && !rem_open)
	{
		if (is_balanced(str))
			puts(str);
		return ;
	}
	while (str[pos])
	{
		if (str[pos] == '(' && rem_open > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, rem_open - 1, rem_close);
			str[pos] = '(';
		}
		else if (str[pos] == ')' && rem_close > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, rem_open, rem_close - 1);
			str[pos] = ')';
		}
		pos++;
	}
}

int	main(int ac, char **av)
{
	char str[256];
	int i;
	int excess_open;
	int excess_close;

	if (ac != 2)
		return (1);
	i = 0;
	while (av[1][i])
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = '\0';
	excess_open = 0;
	excess_close = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '(')
			excess_open++;
		else if (str[i] == ')')
		{
			if (excess_open > 0)
				excess_open--;
			else
				excess_close++;
		}
		i++;
	}
	if (!excess_open && !excess_close)
		puts(str);
	else
		solve(str, 0, excess_open, excess_close);
	return (0);
}