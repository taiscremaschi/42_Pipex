/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:53 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/06/08 12:52:07 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h> /*biblioteca pra erro*/
# include <fcntl.h> /*para dar open e close*/
# include <stdio.h> /*pipe*/
# include <stdlib.h> /*env*/
# include <sys/wait.h> /*biblioteca pro fork, waitpid*/
# include <unistd.h> /*write, dup2*/

int		main(int argc, char **argv, char **env);
void	process(char **argv, int *pipefd, char **env, int process_nbr);
void	error(void);

#endif