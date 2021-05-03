/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_workspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:03:24 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/03 17:01:18 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	reset_workspace(t_info *info)
{
	int			i;
	t_bui_element	**surfaces;

	t_list *curr;
	t_list *temp;

	curr = info->all_layers;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone(&curr, &layer_free);
		curr = temp;	
	}
	curr = info->all_layer_buttons;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone(&curr, &dummy_free_er);
		curr = temp;
	}

	info->all_layers = NULL;
	info->all_layer_buttons = NULL;
	info->layer_amount = 0;
	layer_create(info, info->layer_menu, &info->all_layers, info->layer_amount++);
	info->active_layer = ((t_layer *)info->all_layers->content)->button;
	ft_putstr("Reset workspace done.\n");

	/* OLD
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
