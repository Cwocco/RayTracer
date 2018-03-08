/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_xml.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 12:07:00 by jpicot            #+#    #+#             */
/*   Updated: 2018/03/07 18:37:38 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/inc/libft.h"


//afficher message erreur tout en choisissant valeur retour
//A AJOUTER A LIBFT

int	print_error(char *str, int ret)
{
//	printf("-->PRINT ERROR-->CHAR *STR[%s] | INT RET[%d]\n", str, ret);
	printf("%s", str);
	return (ret);
}
/*


//cree une liste de tag name avec leur arborescence
//0 check les balises enfants obligatoires
//1 check chaine caractere
//2 check int
//3 check vec
//4 check double

t_tag				*set_authorized_tag_infos(void)
{
	static t_tag	tag_names[19] = {
			{"rt", 0, Y, 1},
			{"rt>scene_name", 1, Y, 1},
			{"rt>window", 0, Y, 1},
			{"rt>window>height", 5, Y, 1}
			{"rt>window>width", 5, Y, 1}
			{"rt>camera", 0, Y, 1},
			{"rt>camera>position", 0, Y, 1},
			{"rt>sphere", 0, N, HUGE_VAL},
			{"rt>sphere>position", 3, Y, 1},
			{"rt>sphere>radius", 4, Y, 1},
			{"rt>sphere>colour", 3, Y, 1},
			{"rt>plane", 0, N, HUGE_VAL},
			{"rt>plane>position", 3, Y, 1},
			{"rt>plane>normal", 3, Y, 1},
			{"rt>plane>colour", 3, Y, 1},
			{"rt>light", 0, N, HUGE_VAL},
			{"rt>light>position", 3, P, 1},
			{"rt>light>intensity", 2, P, 1},
			{NULL, -1}
	};
	return (tag_names);
}

//verifie si nom du tag present est autorise

int				looking_for_tag_infos(char *str, t_tag *tag, int quantity_max)
{
	int			i;

	printf("-->LOOKING FOR TAG INFOS-->CHAR *STR[%s] | T_TAG TAG[0]->name[%s] | INT QUANTITY MAX[%d]\n", str, tag[0]->name, quantity_max);
	i = 0;
	while (tag[i]->name)
	{
		if (!strcmp(to_check, tag[i]->name))
			return (tag_names[i]->type);
		i++;
	}
	return (print_error("Bad tag name.\n", -1));
}

//passe au dessus des nombres (int ou float) ou chiffres et check virgule en fonction de count

int				jump_over_the_number(char *str, int type, int count, int number)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '0' && *(str + 1) >= '0' && *(str + 1) <= '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
		str++;
	if (type == 2 && *str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	while (*str > 8 && *str < 13)
		str++;
	if (count != number && str[i] != ',')
		return (print_error("Not enough good values.\n", -1);
	if (str[i] == ',')
		str++;
	return (0);
}

int						my_atof(const char *str, float *d)
{
	unsigned int		neg;
	unsigned int		i;
	unsigned long long	res;
	int					overflow;

	i = 0;
	overflow = -1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	neg = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i++] <= '9' && ++overflow < 12)
		res = (res * 10) + (str[i - 1] - '0');
	if (overflow >= 12 || ((str[neg] == '-' && res > 2147483648) || (str[neg] != '-' && res > 2147483647)))
		return (-1);
	else
	{
		*d = (int)res;
		if (str[neg] == '-')
			*d = res * -1;
		return (0);
	}
}

int						my_atoi(const char *str, int *d)
{
	unsigned int		neg;
	unsigned int		i;
	unsigned long long	res;
	int					overflow;

	i = 0;
	overflow = -1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	neg = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i++] <= '9' && ++overflow < 12)
		res = (res * 10) + (str[i - 1] - '0');
	if (overflow >= 12 || ((str[neg] == '-' && res > 2147483648) || (str[neg] != '-' && res > 2147483647)))
		return (-1);
	else
	{
		*d = (int)res;
		if (str[neg] == '-')
			*d = res * -1;
		return (0);
	}
}

//type 1 pour les int
//type 2 pour les doubles
//PENSER A GERER LES OVERFLOWS, PAS PLUS DE 3 chiffres apres virgule et au dessus pas plus de 1000000

int				check_good_values(char *str, int type, int number, double max)
{
	int			count;
	int			res;
	double		fres;

	str = ft_strchr(str, '>');
	count = 0;
	while (*str)
	{
		res = 0;
		fres = 0;
		while ((*str >= 9 && *str <= 12))
			str++;
		if (type == 1 && my_atoi(str, &res) == -1)
			return (print_error("Overflow float.\n", -1));
		else if (type == 2 && my_atof(str, fres) == -1)
			return (print_error("Overflow float.\n", -1));
		if (*str != '0' && ((type == 1 && res == 0) || (type == 2 && fres == 0)))
			return (print_error("Bad value.\n", -1));
		else if ((type == 1 && res > max) || (type == 2 && fres > max))
			return (print_error("Bad value.\n", -1));
		count++;
		if (jump_over_the_number(str, type, count, number) == -1)
			return (print_error("Bad content.\n", -1));
	}
	return (*str == '<' && *(str + 1) == '/' && count == number) ? 0 : -1;
}

int				is_content_tag_ok(char *str, char *tag, int type)
{
	if (type == 1 && check_good_string(str, NULL))
		return (-1);
	else if (type == 5 && check_good_values(str, 1, 2, 800))
		return (-1);
	else if (type == 3 && check_good_values(str, 2, 3, HUGE_VAL))
		return (-1);
	else if (type == 4 && check_good_values(str, 2, 1, HUGE_VAL))
		return (-1);
}

int				looking_for_required_sons(char *str, char *good_tag, int max)
{
	int			i;
	int			count;
	char		*str;

	printf("-->LOOKING FOR REQUIRED SONS-->CHAR *STR[%s] | STR *GOOD_TAG[%s] | INT MAX[%d]\n", str, good_tag, max);
	i = 0;
	link = ft_strdup(">");
	while (str[i] != NULL)
	{
		if (str[i] == "<" && str[i + 1] != "/")
		{
			if (!tag)
				tag = ft_strdup(&str[i + 1], ft_strulen(&str[i + 1], ">"));
			else
				tag = ft_strjoin(ft_strjoin(tag, ft_strndup(&str[i + 1], ft_strulen(&str[i + 1], ">"))));
			if (!ft_strcmp(good_tag, tag))
				count++;
		}
	}
	return (count > 0 && count <= max) ? 0 : print_error("Required sons not find.\n", -1);
}

//verifie si contenu et fils sont autorises

int				are_required_tags_here(char *str, char *tag, t_tag *tag_infos)
{
	printf("-->ARE REQUIRED TAGS HERE-->CHAR *STR[%s] | CHAR *TAG[%s] | T_TAG TAG_INFOS[0]->NAME[%s]\n", str, tag, tag_infos[0]->name);
	while (tag_infos[i]->name != NULL)
	{
		if (tag_infos[i]->required == Y && looking_for_required_sons(str, tag_infos[i]->name, tag_infos[i]->quantity_max))
				return (-1);
		i++;
	}
}

//check si le nom de la balise est present dans la structure tag_name (avec is_it_good_tag_name)
//et s'il est bien au bon niveau dans l'arboresence

int				are_tags_ok(char *str, t_tag *tag_infos)
{
	char		*tag;
	int			i;
	char		*link;
	int			type;

	printf("-->ARE TAGS OK-->CHAR *STR[%s] | T_TAG TAG_INFOS[0]->NAME[%s]\n", str, tag_infos[0]->name);
	i = 0;
	tag = NULL;
	link = ft_strdup(">");
	type == -1;
	while (str[i])
	{
		if (str[i] == "<" && str[i + 1] != "/")
		{
			if (!tag)
				tag = ft_strdup(&str[i + 1], ft_strulen(&str[i + 1], ">"));
			else
				tag = ft_strjoin(ft_strjoin(tag, ft_strndup(&str[i + 1], ft_strulen(&str[i + 1], link))));
			if ((type = looking_for_tag_infos(tag, tag_infos)) == -1)
				return (-1);
			if ((!type && are_required_tags_here(&str[i], tag, tag_infos)) || (type && is_content_ok(&str[i], tag, type)))
				return (-1);
		}
		else if (str[i] == "<")
		{
			if (!ft_strchr(tag, ">"))
			{
				free(tag);
				tag = NULL;
			}
			else
				tag = ft_strndup(tag, ft_strulen(tag, ">")); //souci lorsque plusieurs ">"
		}
		i++;
	}
}
*/

//A AJOUTER A LIBFT : extrait une chaine entre deux caracteres
//si autre caractere a ou b trouve entre deux on laisse passer et on prend la plus longue chaine

char			*str_cut_between_two_chars(char *str, char a, char b)
{
	int			i;
	int			j;
	int			len;

//	printf("-->STR CUT BETWEEN CHARS-->CHAR *STR[%s] | CHAR A[%c] | CHAR B[%c]\n", str, a, b);
	i = 0;
	while (str[i] != '\0' && str[i] != a)
		i++;
	if (str[i] == '\0')
		return (NULL);
	j = 0;
	while (str[j + i] != '\0' && str[j + i] != b)
		j++;
	if (j == 1)
		return (NULL);
	return(ft_strndup(&str[i + 1], j - 1));
}

//check si les balises ouvertes ont leur balises fermantes et si aucune balise n'est celibataire

int			tag_is_in_love(char *str, int inception)
{
	int		i;
	char	*bracket;
	int		ret;

//	printf("-->TAG IS IN LOVE-->CHAR *STR[%s]\n", str);
	i = 0;
	bracket = NULL;
	if (str == NULL)
		return (print_error("Sortie pour cause: Pointeur nul.\n", -1));
	printf("Nouvelle inception n = %d.\n", inception);
	while (str && str[i] != '\0')
	{
		printf("[%c]\n", str[i]);
		while (str && str[i] != '\0' && str[i] != '<')
		{	
			i++;
			printf("[%c]\n", str[i]);
		}
		if (str[i] == '\0' && !bracket)
		{
			printf("Bonne sortie 1 pour %d.\n", inception);
			return (0);
		}
		else if (str[i] == '\0')
		{
			printf("Sortie de l'inception %d.\n", inception);
			return (print_error("Cuase: Sortie car fin de chaine 1.\n", -1));
		}
		if (str[i] == '<' && !bracket)
		{
			bracket = str_cut_between_two_chars(&str[i], '<', '>');
			printf("new bracket = %s\n", bracket);
			i++;
			printf("[%c]\n", str[i]);
		}
		printf("bracket = %s\n", bracket);
		if (str[i] == '\0' || str[i + 1] == '\0')
		{
			printf("Sortie de l'inception %d.\n", inception);
			return (print_error("Cause: Sortie car fin de chaine 2.\n", -1));
		}
		if (str[i] == '<' && str[i + 1] == '/')
		{
			printf("On compare le bracket a %s", ft_strndup(&str[i + 2], ft_strlen(bracket)));
			if (!ft_strncmp(bracket, &str[i + 2], ft_strlen(bracket)))
			{
				printf("Bracket reinitiaise.\n");
				bracket = NULL;
			}
			else
			{	
				printf("Sortie de l'inception %d.\n", inception);
				return (print_error("Cause: Mauvais tag fermant.\n", -1));
			}
		}
		else if (str[i] == '<' && str[i + 1] != '/' && tag_is_in_love(&str[i], inception + 1))
		{
			printf("Sortie de l'inception %d.\n", inception);
			return (print_error("Cause retour d'inception mauvais.\n", -1));
		}
		i++;
	}
	if (bracket)
		free(bracket);
	bracket = NULL;
	printf("Bonne sortie 2 pour %d.\n", inception);
	return (0);
}


//check si les brackets ouverts ont des fermants et trouver les fermants celibataires
//a bien faire avant tag_is_in_love

int	bracket_is_in_love(char *str)
{
	int	i;
	int	s;

//	printf("-->BRACKET IS IN LOVE-->CHAR *STR[%s]\n", str);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '>')
			return(print_error("\nBracker error.\n", -1));
		if (str[i] == '<')
		{
			s = 1;
			while (str[i + s] != '\0' && str[i + s] != '>' && str[i + s] != '<')
				s++;
			if (str[i + s] == '\0' || str[i + s] == '<')
				return(print_error("\nBracket error.\n", -1));
		}
		i += s + 1;
		s = 0;
	}
	return (print_error("\nBracket is in love.\n", 0));
}

//importe contenu du fichier pour le transformer en une seule string
int					import_file_content(char *source_file, char **content)
{
	int				fd;
	int				ret;
	char				*line;
	char				*tmp;

//	printf("-->ARE REQUIRED TAGS HERE-->CHAR *SOURCE_FILE[%s] | char **CONTENT[NUL]", source_file);
	if ((fd = open(source_file, O_RDONLY)) == -1)
		return(print_error("Error opening file.\n", -1));
	if (!(*content = ft_memalloc(sizeof(char *))))
		return(print_error("Malloc error.\n", -1));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = *content;
		if (!(*content = ft_strjoin(*content, line)))
			return(print_error("Malloc error.\n", -1));
		free(tmp);
		free(line);
	}
	if (close(fd) == -1)
		return(print_error("Error closing file.\n", -1));
	return (0);
}

int				main(int ac, char **av) //import_config
{
	char		*str;
	int			ret;
//	t_tag		*tag;

//	printf("-->IMPORT CONFIG-->INT AC[%d] | CHAR *AV[1][%s]\n", ac, av[1]);
	str = NULL;
	if (ac != 2)
		return (print_error("usage : ./rtv1 source_file\n", -1));
	if (!(ret = import_file_content(av[1], &str)))
	{
//		printf("Contenu content_file (voir ci dessous)\n\n%s", str);
//		tag = set_required_tag_infos();
		if (bracket_is_in_love(str) || tag_is_in_love(str, 0))// || are_tags_ok(str, tag) || is_content_tag_ok(str, tag))
			return (-1);
		return (0);
	}
	else
		return (-1);
}
