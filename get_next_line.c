/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:15:13 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/11/17 18:46:45 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *str, char *temp)
{
	char	*new;

	new = ft_strjoin(str, temp);
	free(str);
	return (new);
}

int		find_line(char **file, char **line)
{
	int		index;
	char	*temp;

	index = 0;
	while ((*file)[index] != '\n' && (*file)[index] != '\0')
		index++;
	*line = ft_strsub(*file, 0, index);
	temp = ft_strdup(*file);
	if (*line == NULL || temp == NULL)
		return (-1);
	ft_strdel(&*file);
	*file = ft_strsub(temp, index + 1, ft_strlen(temp) - index);
	if (*file == NULL)
		return (-1);
	ft_strdel(&temp);
	return (1);
}

int		read_file(int fd, char **file)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];

	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if ((*file = ft_join(*file, buf)) == NULL)
			return (-1);
		if (ft_strchr(*file, '\n'))
			break ;
	}
	return (rd);
}

int		get_next_line(const int fd, char **line)
{
	static char		*file[4096];
	int				rd;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > 4096)
		return (-1);
	if (file[fd] == NULL)
		if ((file[fd] = ft_strnew(0)) == NULL)
			return (-1);
	rd = read_file(fd, &file[fd]);
	if (rd == -1)
		return (-1);
	if (rd == 0 && file[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	return (find_line(&file[fd], &*line));
}
