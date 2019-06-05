/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:38:25 by jschille          #+#    #+#             */
/*   Updated: 2019/06/05 16:50:50 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKER_H
# define LINKER_H
# include <string.h>
# include <stdlib.h>

typedef struct	s_links
{
	void				*link;
	struct s_links		*next;
}				t_links;

void			*ld_malloc(size_t size);
void			free_links(void);

t_links			*g_links;

#endif
