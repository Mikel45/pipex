/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:36:34 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 20:42:31 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	processing(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_msg();
	pid = fork();
	if (pid == -1)
		error_msg();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	heredoc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	heredoc_error(argc, fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			ft_putstr_fd("heredoc> ", 1);
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main_helper(int *output, int *input, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		*output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		heredoc(argv[2], argc);
		return (3);
	}
	*output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	*input = open(argv[1], O_RDONLY, 0777);
	dup2(*input, STDIN_FILENO);
	return (2);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		input;
	int		output;
	pid_t	pid;

	if (argc >= 5)
	{
		i = main_helper(&output, &input, argc, argv);
		while (i < argc - 2)
			processing(argv[i++], envp);
		dup2(output, STDOUT_FILENO);
		pid = fork();
		if (pid == 0)
			exec(argv[argc - 2], envp);
		while (argc-- - 4)
			waitpid(pid, NULL, 0);
	}
	else
		error_bonus();
}
