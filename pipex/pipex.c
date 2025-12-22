/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:47:40 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/22 19:03:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup(int ac, char **av, int *files, int fd[2])
{
	if (ac != 5)
		error_end("Usage : infile cmd1 cmd2 outfile");
	files[0] = open_fd_infile(av[1], O_RDONLY);
	if (files[0] == -1)
	{
		perror("No infile");
		files[0] = open("/dev/null", O_RDONLY);
	}
	files[1] = open_fd_outfile(av[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (files[1] == -1)
		error_end("Cannot open outfile");
	if (pipe(fd) == -1)
		error_end("error pipe");
}

void	run_child(int fd[2], int *files, char *av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		error_end("error fork child1");
	if (pid1 == 0)
		child1(fd, files[0], av[2], envp);
	pid2 = fork();
	if (pid2 < 0)
		error_end("error fork child2");
	if (pid2 == 0)
		child2(fd, files[1], av[3], envp);
	close_fd(fd);
	close(files[0]);
	close(files[1]);
	if (waitpid(pid1, NULL, 0) < 0)
		perror("waitpid pid1");
	if (waitpid(pid2, NULL, 0) < 0)
		perror("waitpid pid2");
}

int	main(int ac, char **av, char **envp)
{
	int	files[2];
	int	fd[2];

	if (ac != 4)
		error_end("Pipe use : infile cmd1 | cmd2 outfile");
	setup(ac, av, files, fd);
	run_child(fd, files, av, envp);
	return (0);
}
