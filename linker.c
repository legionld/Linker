/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:37:53 by jschille          #+#    #+#             */
/*   Updated: 2019/06/05 16:50:28 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linker.h"

void	err_link_out(int e)
{
	if (e == 1)
		exit(0);
}

void	add_link(void *data)
{
	t_links		*tmp;

	if (!g_links)
	{
		if (!(g_links = (t_links*)malloc(sizeof(t_links))))
			err_link_out(1);
		g_links->link = data;
		g_links->next = NULL;
		return ;
	}
	tmp = g_links;
	while (g_links->next)
		g_links = g_links->next;
	if (!(g_links->next = (t_links*)malloc(sizeof(t_links))))
		err_link_out(1);
	g_links->next->link = data;
	g_links->next->next = NULL;
	g_links = tmp;
}

void	*ld_malloc(size_t size)
{
	void	*data;

	if (!(data = malloc(size)))
		err_link_out(1);
	add_link(data);
	return (data);
}

void	free_links(void)
{
	while (g_links)
	{
		free(g_links->link);
		free(g_links);
		g_links = g_links->next;
	}
	free(g_links);
}
