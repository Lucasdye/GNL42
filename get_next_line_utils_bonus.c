/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:27:22 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/13 14:48:49 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	len_total;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((sizeof(char) * len_total) + 1);
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] && (i + j) < (int)len_total)
	{
		p[i + j] = s2[j];
		j++;
	}
	if (s1)
		free((char *)s1);
	p[i + j] = '\0';
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_free(const char *source, char *tmp)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(source) + 1);
	if (!dest || !source)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	if (tmp)
		free (tmp);
	if (dest && *dest == '\0')
	{	
		free(dest);
		dest = NULL;
	}
	return (dest);
}

int	ft_check_rt(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_stash_to_line(const char *stash)
{
	size_t	bytes;
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	bytes = 0;
	while (stash[bytes] && stash[bytes] != '\n')
		bytes++;
	bytes++;
	line = malloc(bytes + 1);
	i = 0;
	while (i < (int)bytes)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
