/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:57:26 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/16 17:07:54 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char *cmd)
{
	char	**cmps;

	if (!cmd)
		error_end("Command not found");
	cmps = ft_split(cmd, ' ');
	if (!cmps)
		error_exit("malloc error");
	return (cmps);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	paths = ft_split(get_path(envp), ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_tab(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

void		exec_cmd(char *cmd, char **envp)
{
	char **args;
	char *path;

	args = split_cmd(cmd);
	path = find_cmd_path(args[0], envp);
	if (!path)
	{
		free_tab(args);
		error_end("Command not found");
	}
	execve(path, args, envp);
	perror("error execve");
	free(path);
	free_tab(args);
	exit(EXIT_FAILURE);
}
