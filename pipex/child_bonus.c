/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:25:46 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/22 17:46:13 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(int infile, int outfile, char *cmd, char **envp)
{
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(infile);
	close(outfile);
	exec_cmd(cmd, envp);
}

void	exec_child(int ac, char **av, char **envp, int infile, int outfile)
{
	int fd[2];
	int pid;
	int i;
	int prev_fd;

	i = 2;
	prev_fd = infile;
	while (i < ac - 1)
	{
		if (i < ac -2)
		{
			if (pipe(fd) == -1)
				error_end("Pipe");
		}
		else
		{
			fd[0] = -1;
			fd[1] = -1;
		}
		pid = fork();
		if (pid == -1)
			error_end("fork");
		if (pid == 0)
		{
			if (i == ac - 2)
				child(prev_fd, outfile, av[1], envp);
			else
				child(prev_fd, fd[1], av[i], envp);
		}
		if (prev_fd != infile)
			close(prev_fd);
		if (i < ac - 2)
		{
			close(fd[1]);
			prev_fd = -1;
		}
		i++;
	}
}