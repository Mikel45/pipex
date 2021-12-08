/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crivers <crivers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:25:58 by crivers           #+#    #+#             */
/*   Updated: 2021/12/08 14:12:00 by crivers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			len++;
		}
		i++;
	}
	return (len);
}

static void	*split_free(char **res, int i)
{
	while (i > 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

static char	**split_alg(int *arr, const char *s, char **res, char c)
{
	arr[0] = 0;
	arr[1] = 0;
	arr[3] = 0;
	while (arr[1] < (int)(word_count(s, c)))
	{
		arr[2] = 0;
		while (s[arr[0]] == c && s[arr[0]])
			arr[0]++;
		arr[3] = arr[0];
		while (s[arr[0]] && s[arr[0]] != c)
		{
			arr[2]++;
			arr[0]++;
		}
		if (arr[2] > 0)
		{
			res[arr[1]++] = ft_substr(s, arr[3], arr[2]);
			if (!res[arr[1] - 1])
				return (split_free(res, arr[1] - 1));
		}
	}
	res[arr[1]] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		arr[4];

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (res)
		res = split_alg(arr, s, res, c);
	return (res);
}
