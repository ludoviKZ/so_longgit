/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:14:26 by lzorzit           #+#    #+#             */
/*   Updated: 2024/10/25 18:14:00 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*ft_strjoingnx(char *s1, char *s2);
void	*ft_malloclen(size_t val1, size_t val2);
int		ft_strchrgnx( const char *s, int c);
int		ft_strlengnx(const char *str);
char	*nextlin(char *line);
char	*cpyret(char *line);
char	*readfil(int fd, char *line);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
int		readerror(int i, char *line, char *prtread);
#endif
