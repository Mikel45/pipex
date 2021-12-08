/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:52:42 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:13:02 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_msg(void)
{
	perror("Something went wrong");
	exit(EXIT_FAILURE);
}

char	*env_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*part_path;
	char	**possible_paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (envp[i] == '\0')
		error_msg();
	possible_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (possible_paths[i])
	{
		part_path = ft_strjoin(possible_paths[i++], "/");
		if (!part_path)
			error_msg();
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!path)
			error_msg();
		if (access(path, F_OK) == 0)
			return (path);
	}
	return (NULL);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(env_path(cmd[0], envp), cmd, envp) == -1)
		error_msg();
}
