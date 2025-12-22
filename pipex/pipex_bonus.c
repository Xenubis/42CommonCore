/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:47:40 by mmusquer          #+#    #+#             */
/*   Updated: 2025/12/22 18:14:10 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;

	if (ac < 5)
		error_end("Pipe use : infile cmd1 .... cmd2 outfile");
	infile = open_fd_infile(av[1], O_RDONLY);
	if (infile == -1)
	{
		perror("No infile");
		infile = open("/dev/null", O_RDONLY);
	}
	outfile = open_fd_outfile(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC);
	if (outfile == -1)
		error_end(av[ac - 1]);
	exec_child(ac, av, envp, infile, outfile);
	close(infile);
	close(outfile);
	while (wait(NULL) > 0)
		;
	return (0);
}
