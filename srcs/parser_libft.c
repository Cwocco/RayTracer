/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:54:34 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/09 09:36:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

void    ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_lstrev(t_list **alst)
{
	t_list *cur;
	t_list *next;
	t_list *prev;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int     ft_tablen(char **str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int     ft_strdigit(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void    ft_deltab(void *content, size_t content_size)
{
	char    **tmp;
	size_t  i;

	i = 0;
	tmp = (char**)content;
	(void)content_size;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

static char         *ft_atod_copy(char *s)
{
	char            *str;
	unsigned int    len;
	unsigned int    i;

	len = ft_strlen(s);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != '.')
			str[i++] = *s;
		++s;
	}
	str[i] = '\0';
	return (str);
}

static unsigned int ft_atod_decimals(char *s)
{
	unsigned int n;

	n = 1;
	while (*s && *s != '.')
		++s;
	if (*s == '.')
		++s;
	while (*s)
	{
		n *= 10;
		++s;
	}
	return (n);
}

double              ft_atod(char *s)
{
	char            *str;
	unsigned int    divider;
	double          ret;

	if (!(str = ft_atod_copy(s)))
		return (0);
	divider = ft_atod_decimals(s);
	ret = (double)ft_atoi(str) / (double)divider;
	free(str);
	return (ret);
}
