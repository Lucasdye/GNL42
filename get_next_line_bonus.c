/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:27:09 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/13 15:12:40 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*stash[1024];
	char			*line;
	char			*buf;
	char			*temp;
	int				buflen;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || fd < 0 || fd >= 1024)
		return (free(buf), NULL);
	buflen = BUFFER_SIZE;
	while (buflen == BUFFER_SIZE && ft_check_rt(stash[fd]) == -1)
	{	
		buflen = read(fd, buf, BUFFER_SIZE);
		if (buflen == -1 || (buflen == 0 && !stash[fd]))
			return (free(buf), NULL);
		buf[buflen] = '\0';
		temp = stash[fd];
		stash[fd] = ft_strjoin_free((char const *)temp, (char const *)buf);
	}
	free(buf);
	temp = stash[fd];
	line = ft_stash_to_line(stash[fd]);
	stash[fd] = ft_strdup_free(temp + ft_strlen(line), temp);
	return (line);
}
/*
int	main()
{
	int fd0, fd1, fd2;
	int i, j;
	char 	*line;
    
	j = 0;
    i = 0;
	fd0 = open("./aulecteur.txt", 0, "O_RDONLY");
    fd1 = open("./aulecteur1.txt", 0, "O_RDONLY");
    fd2 = open("./aulecteur2.txt", 0, "O_RDONLY");
	
	while (j < 10)
	{	
		while (i < 1)
    	{
        	line = get_next_line(fd0);
			printf("return value fd0 %d :%s\n",i , line);
			free(line);
			i++;
	    }
		i = 0;
		while (i < 1)
   		{
     	   line = get_next_line(fd1);
			printf("return value fd1 %d :%s\n",i , line);
			free(line);
			i++;
    	}
		i = 0;
		while (i < 1)
    	{
        	line = get_next_line(fd2);
			printf("return value fd2 %d :%s\n",i , line);
			free(line);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
*/
