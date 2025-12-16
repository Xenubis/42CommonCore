/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:47:40 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/16 17:05:16 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t pid1;
	pid_t pid2;
	int infile;
	int outfile;

	if (ac != 5)
		error_end("Pipe use : infile cmd1 | cmd2 outfile");
	infile = open_fd(av[1], O_RDONLY);
	outfile = open_fd(av[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (!pipe(fd))
		error_end("Error pipe");
	pid1 = fork();
	if (pid1 == 0)
		child1(fd, infile, av[3], envp);
	pid2 = fork();
	if (pid2 == 0)
		child2(fd, outfile, av[3], envp);
	close_fd(fd);
	close(infile);
	close(outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}