#include <math.h>
#include <stdio.h>

typedef struct s_city
{
	float	x;
	float	y;
}			t_city;

float	dist(t_city *a, t_city *b)
{
	float	dx;
	float	dy;

	dx = a->x - b->x;
	dy = a->y - b->y;
	return (sqrtf(dx * dx + dy * dy));
}

void	swap(int *a, int *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	path_len(t_city *cities, int *path, int n)
{
	float	total;
	int		i;

	total = 0;
	i = 0;
	while (i < n - 1)
	{
		total += dist(&cities[path[i]], &cities[path[i + 1]]);
		i++;
	}
	total += dist(&cities[path[n - 1]], &cities[path[0]]);
	return (total);
}

int	parsing(t_city *cities)
{
	int		n;
	float	x;
	float	y;

	n = 0;
	while (scanf("%f, %f\n", &x, &y) == 2)
	{
		cities[n].x = x;
		cities[n].y = y;
		n++;
	}
	return (n);
}

void	init_path(int *path, int n)
{
	int i;
	i = 0;
	while (i < n)
	{
		path[i] = i;
		i++;
	}
}

void	permute(t_city *cities, int *path, int start, int n, float *min)
{
	float len;
	int i;

	if (start == n)
	{
		len = path_len(cities, path, n);
		if (len < *min)
			*min = len;
		return ;
	}
	i = start;
	while (i < n)
	{
		swap(&path[start], &path[i]);
		permute(cities, path, start + 1, n, min);
		swap(&path[start], &path[i]);
		i++;
	}
}

int	main(void)
{
	t_city cities[11];
	int	path[12];
	int n;
	float min;

	n = parsing(cities);
	if (n <= 1)
	{
		fprintf(stdout, "0.00\n");
		return (0);
	}
	init_path(path, n);
	min = path_len(cities, path, n);
	permute(cities, path, 1, n, &min);
	fprintf(stdout, "%.2f\n", min);
	return (0);
}