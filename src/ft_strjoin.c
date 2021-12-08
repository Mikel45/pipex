/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:10 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:08 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res)
	{
		i = 0;
		j = 0;
		while (s1[i])
			res[j++] = s1[i++];
		i = 0;
		while (s2[i])
			res[j++] = s2[i++];
		res[j] = '\0';
	}
	return (res);
}
