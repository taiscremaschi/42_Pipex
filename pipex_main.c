/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:08:51 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/06/08 13:04:33 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		exit(write(2, "Error, insert 5 arguments\n", 27));
	if (pipe(pipefd) == -1)
		error();
	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
		process(argv, pipefd, env, 1);
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		process(argv, pipefd, env, 2);
	close(pipefd[0]);
	waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
}
