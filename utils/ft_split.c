/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:42:21 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/09 14:53:07 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	split_array(char **result, char const *s, char c)
{
	size_t	j;
	size_t	word;
	size_t	i;

	i = 0;
	word = -1;
	while (s[i])
	{
		if (check_c(s[i], c))
			i++;
		else
		{
			j = 0;
			while (!check_c(s[i + j], c))
				j++;
			result[++word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[word])
			{
				array_free(result, word);
				return ;
			}
			ft_strncpy(result[word], s + i, j);
			i += j;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (check_c(s[i + 1], c) && !check_c(s[i], c))
			word++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (0);
	result[word] = 0;
	if (word == 0)
		return (result);
	split_array(result, s, c);
	return (result);
}

int	check_c(char str_c, char c)
{
	if (str_c == c)
		return (1);
	if (str_c == '\0')
		return (1);
	return (0);
}

void	ft_strncpy(char *dest, char const *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

void	array_free(char **result, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(result[i]);
		i++;
	}
	free(result);
}
