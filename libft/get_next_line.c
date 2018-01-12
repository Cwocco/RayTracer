/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:03:40 by nboste            #+#    #+#             */
/*   Updated: 2016/12/08 01:08:18 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		del_buffer(void *content, size_t content_size)
{
	free(((t_buffer *)content)->data);
	free(((t_buffer *)content));
	content_size = content_size + 1;
}

static int		destroy_return(t_list **buffers, t_buffer **buffer,
				char **line, int ret)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *buffers;
	prev = NULL;
	ft_strdel(line);
	while (tmp)
	{
		if ((t_buffer *)tmp->content == *buffer)
		{
			if (prev != NULL)
				prev->next = tmp->next;
			ft_lstdelone(&tmp, del_buffer);
			if (prev == NULL)
				*buffers = NULL;
			return (ret);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

static t_buffer	*get_buffer(t_list **buffers, int fd)
{
	t_list		*tmp;
	t_buffer	*buffer;

	tmp = *buffers;
	while (tmp)
	{
		if (((t_buffer *)(tmp->content))->fd == fd)
			return ((t_buffer *)(tmp->content));
		tmp = tmp->next;
	}
	if (!(buffer = (t_buffer *)malloc(sizeof(t_buffer))))
		return (NULL);
	if (!(buffer->data = ft_strnew(BUFF_SIZE)))
	{
		free(buffer);
		return (NULL);
	}
	buffer->remaining_data = NULL;
	buffer->fd = fd;
	buffer->last = NULL;
	buffer->eof = 0;
	ft_lstadd(buffers, ft_lstnew((void *)buffer, sizeof(t_buffer)));
	free(buffer);
	return ((t_buffer *)(*buffers)->content);
}

static int		process_buffer(t_buffer *buffer, char **ret)
{
	char	*tmp;
	char	*rem;
	int		flag;

	flag = 1;
	if (buffer->remaining_data != NULL)
	{
		rem = buffer->remaining_data;
		if ((tmp = ft_strchr(buffer->remaining_data, (int)'\n')))
		{
			*tmp = '\0';
			buffer->remaining_data = tmp + 1 >= buffer->last ? NULL : tmp + 1;
		}
		else if (buffer->eof)
			buffer->remaining_data = NULL;
		else
			flag = 0;
		tmp = *ret;
		if (!(*ret = ft_strjoin(*ret, rem)))
			return (0);
		free(tmp);
		return (flag);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*l_buffers;
	t_buffer		*buffer;
	int				nb_read;

	if (!line || !(*line = ft_strnew(0)) || fd < 0)
		return (-1);
	buffer = get_buffer(&l_buffers, fd);
	if (buffer->eof && buffer->remaining_data == NULL)
		return (destroy_return(&l_buffers, &buffer, line, 0));
	if (process_buffer(buffer, line))
		return (1);
	while ((nb_read = read(fd, buffer->data, BUFF_SIZE)) >= 0)
	{
		if (nb_read == 0 && **line == '\0')
			return (destroy_return(&l_buffers, &buffer, line, 0));
		buffer->last = buffer->data + nb_read;
		*buffer->last = '\0';
		buffer->remaining_data = buffer->data;
		if (nb_read < BUFF_SIZE)
			buffer->eof = 1;
		if (process_buffer(buffer, line))
			return (1);
	}
	return (destroy_return(&l_buffers, &buffer, line, -1));
}
