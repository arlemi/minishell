/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 17:01:52 by jguthert          #+#    #+#             */
/*   Updated: 2016/04/25 17:59:38 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			shell(t_list *av_list, t_list **g_env, t_list **l_env)
{
	int		ret;

	ret = 0;
	while (av_list != NULL)
	{
		if (builtin(((t_av *)av_list->content), g_env, l_env) == 0)
			return (0);
//		ret = do_exec(*((t_av *)av_list->content), *g_env, *l_env);
		if (ret == 1)
			print_error(AV_INIT("minishell", ((t_av *)av_list->content)->cmd), 7);
		av_list = av_list->next;
	}
	return (0);
}
