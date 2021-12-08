/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:35 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:22 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0 && ft_strlen(needle) != 0)
		return (NULL);
	if (!needle[0])
		return ((char *) haystack);
	while (len > 0 && *haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0
			&& len >= ft_strlen(needle))
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
