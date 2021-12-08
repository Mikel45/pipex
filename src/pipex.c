/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:05:24 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 19:09:39 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int	inputfile;

	inputfile = open(argv[1], O_RDONLY, 0777);
	if (inputfile == -1)
		error_msg();
	dup2(fd[1], STDOUT_FILENO);
	dup2(inputfile, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	outputfile;

	outputfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outputfile == -1)
		error_msg();
	dup2(fd[0], STDIN_FILENO);
	dup2(outputfile, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int			fd[2];
	pid_t		pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_msg();
		pid = fork();
		if (pid == -1)
			error_msg();
		if (pid == 0)
			child_process(fd, argv, envp);
		else
		{
			parent_process(fd, argv, envp);
			waitpid(pid, NULL, 0);
			close(fd[0]);
			close(fd[1]);
		}
	}
	else
		ft_putstr_fd("format: ./pipex inputfile cmd1 cmd2 outputfile", 2);
	return (0);
}
