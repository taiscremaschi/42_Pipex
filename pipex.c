/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:30:07 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/06/06 19:35:15 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **path, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*temp;

	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK) != -1)
			return (cmd_path);
		free(cmd_path);
	}
	write(2, "Error, Command invalid\n", 24);
	exit(127);
}

char	*command(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*cmd_path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = ft_split(&env[i][5], ':');
	cmd_path = check_path(path, cmd);
	return (cmd_path);
}

void	run(char *cmd, char **env)
{
	char	**list_cmd;
	char	*path;

	list_cmd = ft_split(cmd, ' ');
	cmd = list_cmd[0];
	path = command(cmd, env);
	if (execve(path, list_cmd, env) == -1)
		error();
}

void	process(char **argv, int *pipefd, char **env, int process_nbr)
{
	int	file1;
	int	file2;

	if (process_nbr == 1)
	{
		file1 = open(argv[1], O_RDONLY);
		if (file1 < 0)
			error();
		close(pipefd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(file1);
		run(argv[2], env);
	}
	else
	{
		file2 = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (file2 < 0)
			error();
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		dup2(file2, STDOUT_FILENO);
		close(file2);
		run(argv[3], env);
	}
}
