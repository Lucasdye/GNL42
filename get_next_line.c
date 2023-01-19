/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:27:09 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/13 14:20:56 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	char			*buf;
	char			*temp;
	int				buflen;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || fd < 0 || fd >= 1000)
		return (free(buf), NULL);
	buflen = BUFFER_SIZE;
	while (buflen == BUFFER_SIZE && ft_check_rt(stash) == -1)
	{	
		buflen = read(fd, buf, BUFFER_SIZE);
		if (buflen == -1 || (buflen == 0 && !stash))
			return (free(buf), NULL);
		buf[buflen] = '\0';
		temp = stash;
		stash = ft_strjoin_free((char const *)temp, (char const *)buf);
	}
	free(buf);
	temp = stash;
	line = ft_stash_to_line(stash);
	stash = ft_strdup_free(temp + ft_strlen(line), temp);
	return (line);
}
/*
int	main()
{
	int fd;
    int i;
	char 	*line;
    
    i = 0;
	fd = open("./aulecteur.txt", 0, "O_RDONLY");
    while (i < 42)
    {
        line = get_next_line(fd);
		printf("return value %d :%s\n",i , line);
		//if (i == 1)
		//	close(fd);
		free(line);
		i++;
    }
    return (0);
}
*/
