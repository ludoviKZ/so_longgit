/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:14:23 by lzorzit           #+#    #+#             */
/*   Updated: 2024/11/20 16:22:56 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <fcntl.h>*/
#include "libft.h"

int	readerror(int i, char *line, char *prtread)
{
	if (i == -1)
	{
		if (line != NULL)
			free (line);
		if (prtread != NULL)
			free (prtread);
		line = NULL;
		return (0);
	}
	return (1);
}

char	*nextlin(char *line)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if (line[i] == '\n')
		i++;
	cpy = ft_malloclen(sizeof(char), (ft_strlen(line) - i + 1));
	while (line[i] != '\0')
	{
		cpy[j] = line[i];
		i++;
		j++;
	}
	free (line);
	return (cpy);
}

char	*cpyret(char *line)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	if (line[i] == '\n')
		i++;
	if (i == 0)
		return (0);
	cpy = ft_malloclen(i + 1, sizeof(char));
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		cpy[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		cpy[i++] = '\n';
	return (cpy);
}

char	*readfil(int fd, char *line)
{
	char	*prtread;
	int		i;

	i = 1;
	if (!line)
		line = ft_malloclen(1, 1);
	prtread = ft_malloclen(sizeof(char), BUFFER_SIZE + 1);
	while (i > 0)
	{
		i = read(fd, prtread, BUFFER_SIZE);
		if (i == -1)
		{
			readerror(i, line, prtread);
			return (0);
		}
		prtread[i] = 0;
		line = ft_strjoin(line, prtread);
		if ((ft_strchr (prtread, '\n')) > 0)
			break ;
	}
	return (free(prtread), line);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*line[4065];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = readfil(fd, line[fd]);
	if (!line[fd])
		return (0);
	ret = cpyret(line[fd]);
	line[fd] = nextlin(line[fd]);
	return (ret);
}
/*int main(void)
{
  int 	rep;
 int    fd;
 char  *next_line;
 int  count;
	rep = 0;
  count = 0;
  fd = open("empty.txt", O_RDONLY);
  while(rep < 50)
	{
  	next_line = get_next_line(fd);
 	count++;
 	printf("%i[%d]:%s\n", ft_strlen(next_line), count, next_line);
 	free(next_line);
	rep ++;
	}
  close(fd);
  return (0);
}*/
