/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:08:46 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/20 21:31:36 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(int fd, char *buf, char *back)
{
	int		cnt;
	char	*curptr;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (NULL);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!back)
			back = ft_strdup("");
		curptr = back;
		back = ft_strjoin(curptr, buf);
		if (!back)
			return (0);
		free(curptr);
		curptr = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (back);
}

char	*make_back(char *c)
{
	int		i;
	int		cs;
	char	*rlt;

	cs = 0;
	while (c[cs])
		cs++;
	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
		i++;
	if (c[i] == '\0')
		return (0);
	rlt = ft_substr(c, i + 1, cs - i);
	if (rlt[0] == '\0')
	{
		free(rlt);
		rlt = NULL;
	}
	if (rlt == NULL)
		return (0);
	c[i + 1] = '\0';
	return (rlt);
}

char	*get_next_line(int fd)
{
	static char	*back[20000];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	line = make_line(fd, buf, back[fd]);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(back[fd]);
		back[fd] = NULL;
		return (0);
	}
	back[fd] = make_back(line);
	return (line);
}
