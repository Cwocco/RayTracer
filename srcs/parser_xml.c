/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_xml.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 12:07:00 by jpicot            #+#    #+#             */
/*   Updated: 2018/03/08 15:29:00 by jpicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/inc/libft.h"

//cree une liste de tag name avec leur arborescence
//0 check les balises enfants obligatoires
//1 check chaine caractere
//2 check int
//3 check vec
//4 check double

typedef struct		s_tag
{
	char			*name;
	int				type; //0 sons, 1 str, 2 int, 3 double, 4 vec
	int				n_content; //nombre de content a exporter
	int				n_entity_max; //nombre max de tags du meme nom
	char			required; //'Y'(es) or N(o)
}					t_tag;

static t_tag	tag[74] = {
	{"rt",  0, 0, 1, 'Y'},
	{"rt>basic",  0, 0, 1, 'Y'},
	{"rt>basic>program",  0, 0, 1, 'Y'},
	{"rt>basic>program>size",  2, 2, 1, 'Y'},
	{"rt>basic>program>title",  1, 1, 1, 'Y'},
	{"rt>basic>program>ambient_intensity",  2, 1, 1, 'Y'},
	{"rt>basic>program>ressource",  0, 0, 1, 'Y'},
	{"rt>basic>program>ressource>icon",  1, 1, 1, 'Y'},
	{"rt>basic>program>ressource>mouse",  1, 1, 1, 'Y'},
	{"rt>basic>camera",  0, 0, 1, 'Y'},
	{"rt>basic>camera>position",  2, 3, 1, 'Y'},
	{"rt>basic>camera>rotation",  2, 3, 1, 'Y'},
	{"rt>basic>camera>field_of_view",  2, 1, 1, 'Y'},
	{"rt>object",  0, 0, 1, 'Y'},
	{"rt>object>sphere",  0, 0, 50, 'N'},
	{"rt>object>sphere>position",  2, 3, 1, 'Y'},
	{"rt>object>sphere>radius",  3, 1, 1, 'Y'},
	{"rt>object>sphere>rotation",  3, 3, 1, 'Y'},
	{"rt>object>sphere>material",  0, 0, 1, 'Y'},
	{"rt>object>sphere>material>ambient",  2, 3, 1, 'Y'},
	{"rt>object>sphere>material>diffuse",  2, 3, 1, 'Y'},
	{"rt>object>sphere>material>specular",  0, 0, 1, 'Y'},
	{"rt>object>sphere>reflection",  3, 1, 1, 'Y'},
	{"rt>object>sphere>refraction",  3, 1, 1, 'Y'},
	{"rt>object>sphere>texture",  2, 1, 1, 'Y'},
	{"rt>object>sphere>bump_coefficient",  3, 1, 1, 'Y'},
	{"rt>object>plane",  0, 0, 50, 'N'},
	{"rt>object>plane>position",  2, 3, 1, 'Y'},
	{"rt>object>plane>normale",  2, 3, 1, 'Y'},
	{"rt>object>plane>rotation",  3, 3, 1, 'Y'},
	{"rt>object>plane>material",  0, 0, 1, 'Y'},
	{"rt>object>plane>material>ambient",  2, 3, 1, 'Y'},
	{"rt>object>plane>material>diffuse",  2, 3, 1, 'Y'},
	{"rt>object>plane>material>specular",  0, 0, 1, 'Y'},
	{"rt>object>plane>reflection",  3, 1, 1, 'Y'},
	{"rt>object>plane>refraction",  3, 1, 1, 'Y'},
	{"rt>object>plane>texture",  2, 1, 1, 'Y'},
	{"rt>object>plane>bump_coefficient",  3, 1, 1, 'Y'},
	{"rt>object>cone",  0, 0, 50, 'N'},
	{"rt>object>cone>position",  2, 3, 1, 'Y'},
	{"rt>object>cone>radius",  3, 1, 1, 'Y'},
	{"rt>object>cone>rotation",  3, 3, 1, 'Y'},
	{"rt>object>cone>material",  0, 0, 1, 'Y'},
	{"rt>object>cone>material>ambient",  2, 3, 1, 'Y'},
	{"rt>object>cone>material>diffuse",  2, 3, 1, 'Y'},
	{"rt>object>cone>material>specular",  0, 0, 1, 'Y'},
	{"rt>object>cone>reflection",  3, 1, 1, 'Y'},
	{"rt>object>cone>refraction",  3, 1, 1, 'Y'},
	{"rt>object>cone>texture",  2, 1, 1, 'Y'},
	{"rt>object>cone>bump_coefficient",  3, 1, 1, 'Y'},
	{"rt>object>cylinder",  0, 0, 50, 'N'},
	{"rt>object>cylinder>position",  2, 3, 1, 'Y'},
	{"rt>object>cylinder>radius",  3, 1, 1, 'Y'},
	{"rt>object>cylinder>rotation",  3, 3, 1, 'Y'},
	{"rt>object>cylinder>material",  0, 0, 1, 'Y'},
	{"rt>object>cylinder>material>ambient",  2, 3, 1, 'Y'},
	{"rt>object>cylinder>material>diffuse",  2, 3, 1, 'Y'},
	{"rt>object>cylinder>material>specular",  0, 0, 1, 'Y'},
	{"rt>object>cylinder>reflection",  3, 1, 1, 'Y'},
	{"rt>object>cylinder>refraction",  3, 1, 1, 'Y'},
	{"rt>object>cylinder>texture",  2, 1, 1, 'Y'},
	{"rt>object>cylinder>bump_coefficient",  3, 1, 1, 'Y'},
	{"rt>light",  0, 0, 1, 'Y'},
	{"rt>light>point",  0, 0, 1, 'Y'},
	{"rt>light>point>position",  2, 3, 1, 'Y'},
	{"rt>light>point>direction",  2, 3, 1, 'Y'},
	{"rt>light>point>color",  2, 3, 1, 'Y'},
	{"rt>light>point>intensity",  3, 1, 1, 'Y'},
	{"rt>light>point>color",  2, 3, 1, 'Y'},
	{"rt>option",  0, 0, 1, 'Y'},
	{"rt>option>anti_aliasing",  2, 1, 1, 'Y'},
	{"rt>option>sepia",  2, 1, 1, 'Y'},
	{"rt>option>fifty_shades",  2, 1, 1, 'Y'},
	{"rt>option>colour_blind",  2, 1, 1, 'Y'},
};


//afficher message erreur tout en choisissant valeur retour
//A AJOUTER A LIBFT

int	print_error(char *str, int ret)
{
	//	printf("-->PRINT ERROR-->CHAR *STR[%s] | INT RET[%d]\n", str, ret);
	printf("%s", str);
	return (ret);
}
/*
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

*/


/*
   int				looking_for_required_sons(char *str, char *good_tag, int max)
   {
   int			i;
   int			count;
   char		*str;

   printf("-->LOOKING FOR REQUIRED SONS-->CHAR *STR[%s] | STR *GOOD_TAG[%s] | INT MAX[%d]\n", str, good_tag, max);
   i = 0;
   link = ">");
   while (str[i] != NULL)
   {
   if (str[i] == "<" && str[i + 1] != "/")
   {
   if (!tag)
   tag = &str[i + 1], ft_strulen(&str[i + 1], ">"));
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
if (tag_infos[i]->required == 'Y' && looking_for_required_sons(str, tag_infos[i]->name, tag_infos[i]->quantity_max))
return (-1);
i++;
}
}

//check si le nom de la balise est present dans la structure tag_name (avec is_it_good_tag_name)
//et s'il est bien au bon niveau dans l'arboresence
*/


//verifie si nom du tag present est autorise

int				looking_for_tag_names(char *to_check)
{
	int			i;

	i = 0;
	while (i < 74)
	{
		if (!ft_strcmp(to_check, tag[i].name))
			return (0);
		i++;
	}
	return (print_error("Bad tag name.\n", -1));
}

int				are_tags_ok(char *str)
{
	char		*tmp;
	int			i;
	char		c;
	int			type;
	char		*join;

	i = 0;
	tmp = NULL;
	c = '>';
	type = -1;
	if (str == NULL && *str != '\0')
		return (print_error("Some tags are not allowed.\n", -1));
	while (str[i] != '\0')
	{
		printf("[%c] b\n", str[i]);
		if (str[i] == '<' && str[i + 1] != '/')
		{
			if (!tmp)
			{
				tmp = ft_strndup(&str[i + 1], ft_strulen(&str[i + 1], '>'));
				printf("New tmp = %s\n", tmp);
			}
			else
			{
				join = ft_strndup(&str[i], ft_strulen(&str[i], '>'));
				join = ft_strjoin(&str[i], &c);
				tmp = ft_strjoin(tmp, join);
				printf("Ajout a tmp = %s\n", tmp);
			}
			if (looking_for_tag_names(tmp) == -1)
			{
				printf("Balise non autorisee\n");
				return (print_error("Some tags are not allowed.\n", -1));
			}
			//			if ((!type && are_required_tags_here(&str[i], tmp, tag)) || (type && is_content_ok(&str[i], tmp, type)))
			//				return (-1);
		}
		else if (str[i] == '<')
		{
			if (!ft_strchr(tmp, '>'))
			{
				printf("Tmp delete\n");
				free(tmp);
				tmp = NULL;
			}
			else
			{
				tmp = ft_strndup(tmp, ft_strulen(tmp, '>')); //souci lorsque plusieurs ">"
				printf("Tmp raccourci = %s\n", tmp);
			}
		}
		i++;
	}
	printf("are tags ok OK.\n");
	return (0);
}


//check si les balises ouvertes ont leur balises fermantes et si aucune balise n'est celibataire

int			tag_is_in_love(char *str, int r, int *i)
{
	int		delete;
	char	*t1;
	char	*t2;

	if (str == NULL || str[*i] == '\0')
		return (print_error("Tag error.\n", -1));
	t1 = NULL;
	t2 = NULL;
	while (str[*i] != '\0')
	{
		while (str[*i] != '<' && str[*i] != '\0')
			(*i)++;
		if (str[*i] == '<' && str[*i + 1] != '/' && !t1)
		{
			t1 = &str[*i + 1];
			(*i)++;
		}
		while (str[*i] != '<' && str[*i] != '\0')
			(*i)++;
		if (str[*i] == '<' && str[*i + 1] == '/')
		{
			t2 = &str[*i + 2];
			if ((t1 == NULL && !r) || (t1 != NULL && *t1 == '\0') || *t2 == '\0')
				return (print_error("Tag error.\n", -1));
			else if (t1 == NULL)
				return (0);
			else if (ft_strncmp(t1, t2, ft_strulen(t1, '>')))
				return (print_error("Tag error.\n", -1));
			t1 = NULL;
			t2 = NULL;
		}
		else if (str[*i] == '<' && str[*i + 1] != '/')
		{
			if (tag_is_in_love(str, r + 1, i))
				return (print_error("Tag error.\n", -1));
			(*i)--;
		}
		else if (t1 != NULL)
			return (print_error("Tag error.\n", -1));
		if (str[*i] != '\0')
			(*i)++;
	}
	return (t1 == NULL) ? print_error("Tag is in love.\n", 0) : print_error("Tag error.\n", -1);
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

//my_strdup a faire avec des exit


int				main(int ac, char **av) //import_config
{
	char		*str;
	int			ret;
	int			i;

	//	printf("-->IMPORT CONFIG-->INT AC[%d] | CHAR *AV[1][%s]\n", ac, av[1]);
	str = NULL;
	i = 0;
	if (ac != 2)
		return (print_error("usage : ./rtv1 source_file\n", -1));
	if (!(ret = import_file_content(av[1], &str)))
	{
		//		printf("Contenu content_file (voir ci dessous)\n\n%s", str);
		if (bracket_is_in_love(str) || tag_is_in_love(str, 0, &i) || are_tags_ok(str)) //|| is_content_tag_ok(str, tag))
			return (-1);
		printf("OK\n");
		return (0);
	}
	else
		return (-1);
}
