/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:48:01 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/22 18:14:38 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX__BONUS_H
# define PIPEX__BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	**split_cmd(char *cmd);
char	*get_path(char **envp);
char	*find_cmd_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);

void	child(int infile, int oufiles, char *cmd, char **envp);
void	exec_child(int ac, char **av, char **envp, int infile, int outfile);

void	error_end(char *msg);
void	free_tab(char **tab);
int		open_fd_outfile(char *file, int flag);
int		open_fd_infile(char *file, int flag);
void	close_fd(int *fd);

#endif