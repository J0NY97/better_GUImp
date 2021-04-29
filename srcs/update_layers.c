/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_layers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:51:10 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/29 16:37:20 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	update_layers(t_info *info)
{
	int			i = 0;
	SDL_Surface *new_surf;
	t_xywh coord;
	
	t_list *curr;
	
	coord = info->screen_surface->position;
	SDL_FillRect(info->screen_surface->active_surface, &(SDL_Rect) {0, 0, coord.w, coord.h}, 0xffffffff);
	curr = info->all_layers;
	while (curr)
	{
		t_layer *layer = curr->content;
		coord = layer->drawing->position;
		SDL_BlitSurface(layer->drawing->active_surface, NULL, info->screen_surface->active_surface, NULL);
		// TODO: use the aspect ratio thingy.
		SDL_BlitScaled(layer->drawing->active_surface, NULL, layer->element->active_surface, NULL);

		shadow(layer->button);
		shadow(layer->element);

		curr = curr->next;
	}
	/*
	i = -1;
	while (++i < info->layer_amount)
	{
		new_surf = ft_scale_surface_aspect(info->drawing_surface[i]->surface,
											info->layer_layers[i]->surface->w,
											info->layer_layers[i]->surface->h);
		SDL_BlitSurface(new_surf, NULL, info->layer_layers[i]->surface, NULL);
		SDL_FreeSurface(new_surf);
	}
	ft_update_background(info->screen_surface->surface,
			info->drawing_surface[0]->bg_color);
	i = -1;
	while (++i < info->layer_amount)
	{
		SDL_BlitScaled(info->drawing_surface[i]->surface, NULL,
				info->screen_surface->surface, NULL);
	}
	*/
}
