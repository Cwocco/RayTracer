/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:03:32 by nboste            #+#    #+#             */
/*   Updated: 2016/12/08 01:07:50 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define BUFF_SIZE 3200

typedef struct	s_buffer
{
	int		fd;
	char	*data;
	char	*remaining_data;
	char	*last;
	int		eof;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif
