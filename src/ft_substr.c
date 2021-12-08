/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:27 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:31 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) <= len)
		size = ft_strlen(s + start);
	else
		size = len;
	res = malloc(size + 1);
	if (res)
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			if (i >= start && j < size)
				res[j++] = s[i];
			i++;
		}
		res[j] = '\0';
	}
	return (res);
}
