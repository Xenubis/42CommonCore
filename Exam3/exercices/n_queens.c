#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *board, int col, int row)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col || board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void print_solution(int *board, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void solve(int *board, int n, int col)
{
	int row;

	if (col == n)
	{
		print_solution(board, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, n, col + 1);
		}
		row ++;
	}
}

int	main(int ac, char **av)
{
	int n;
	int *board;
	
	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n <= 0)
		return (1);
	board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	solve(board, n, 0);
	free(board);
	return (0);
}