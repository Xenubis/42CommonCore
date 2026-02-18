#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int i;
	static int r;
    char *line;
    int j;
	
	j = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(10000);
    if (!line)
        return (NULL);
    while (1)
    {	
        if (i >= r)
        {
            i = 0;
            r = read(fd, buf, BUFFER_SIZE);
            if (r <= 0)
                break ;
        }
        line[j++] = buf[i++];
        if (line[j - 1] == '\n')
            break ;
    }
    if (j == 0)
    {
        free(line);
        return (NULL);
    }
	if (r < 0)
	{
		free(line);
		return (NULL);
	}
    line[j] = '\0';
    return (line);
}
