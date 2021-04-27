/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_workspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:03:24 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 12:59:38 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	reset_workspace(SDL_Event e, t_bui_element *elem)
{
	int			i;
	t_bui_element	**surfaces;

	// TODO: not sure what is happening here.
	/*
	surfaces = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		i = -1;
		while (++i < LAYER_NBR)
		{
			SDL_FreeSurface(surfaces[i]->surface);
			surfaces[i]->surface = ft_create_rgba_surface(surfaces[i]->coord.w,
					surfaces[i]->coord.h);
		}
	}
	*/
}
