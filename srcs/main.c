/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:48:41 by nboste            #+#    #+#             */
/*   Updated: 2017/10/30 13:50:25 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_env	env;

	env.argc = argc;
	env.argv = argv;
	init(&env);
	process(&env);
	destroy(&env);
	return (0);
}
