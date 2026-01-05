/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:57:26 by mmusquer          #+#    #+#             */
/*   Updated: 2026/01/05 17:37:02 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char *cmd)
{
	char	**args;

	if (!cmd || cmd[0] == '\0')
	{
		write(2, "Error: Command", 14);
		exit(127);
	}
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		if (args)
			free(args);
		write(2, "Error: split fail", 17);
		exit(127);
	}
	return (args);
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

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_cmd(cmd);
	path = find_cmd_path(args[0], envp);
	if (!path)
	{
		free_tab(args);
		write(2, "Command not found", 17);
		exit(127);
	}
	execve(path, args, envp);
	perror("error execve");
	free(path);
	free_tab(args);
	exit(EXIT_FAILURE);
}
