/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:48:01 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/16 17:08:38 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

char	**split_cmd(char *cmd);
char	*get_path(char **envp);
char	*find_cmd_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);

void	child1(int *fd, int infiles, char *cmd, char **envp);
void	child2(int *fd, int outfiles, char *cmd, char **envp);

void	error_end(char *msg);
void	free_tab(char **tab);
int		open_fd(char *file, int flag);
void	close_fd(int *fd);

#endif