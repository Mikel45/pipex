/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:08:11 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:58 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	heredoc_error(int argc, int *fd)
{
	if (argc < 6)
		error_msg();
	if (pipe(fd) == -1)
		error_msg();
}

void	error_bonus(void)
{
	ft_putstr_fd("Format: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 2);
	ft_putstr_fd("\nFormat: ./pipex here_doc LIMITER cmd cmd1 file", 2);
	exit(EXIT_FAILURE);
}
