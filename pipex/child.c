/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:25:46 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/16 14:59:12 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *fd, int infiles, char *cmd, char **envp)
{
	dup2(infiles, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_fd(fd);
	exec_cmd(cmd, envp);
}

void	child2(int *fd, int outfiles, char *cmd, char **envp)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(outfiles, STDOUT_FILENO);
	close_fd(fd);
	exec_cmd(cmd, envp);
}