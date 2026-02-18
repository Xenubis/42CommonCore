#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int replace_all(char *buf, int len, char *pattern, int plen)
{
    char *pos;
    int offset = 0;
    
    while ((pos = memmem(buf + offset, len - offset, pattern, plen)) != NULL)
    {
        *pos = '*';
        memmove(pos + 1, pos + plen, len - (pos - buf) - plen);
        len -= (plen - 1);
        offset = (pos - buf) + 1;
    }
    return len; 
}

int main(int ac, char **av)
{
	char *pattern;
	int plen;
	char *buf;
	int saved;
	int bytes_read;
	int total;
	int to_write;

	if (ac != 2 || !av[1] || !av[1][0])
		return (1);
	pattern = av[1];
	plen = strlen(pattern);
	buf = malloc(BUFFER_SIZE + plen);
	if (!buf)
	{
		perror("Error");
    	return (1);
	}
	saved = 0;
	while ((bytes_read = read(0, buf + saved, BUFFER_SIZE)) > 0)
	{
		total = saved + bytes_read;
		replace_all(buf, total, pattern, plen);
		to_write = (bytes_read == BUFFER_SIZE) ? total - (plen - 1) : total;
		write(1, buf, to_write);
		saved = total - to_write;
		if (saved > 0)
			memmove(buf, buf + to_write, saved);
	}
	if(bytes_read < 0)
	{
		perror("Error");
		free(buf);
    	return (1);
	}
	free(buf);
	return (0);
}
