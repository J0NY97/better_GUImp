/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:06:19 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 13:01:31 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	open_button(SDL_Event e, t_bui_element *elem)
{
	char		*file;
	t_brush		*brush;
	SDL_Rect	temp;
	t_bui_element	**surfaces;
	SDL_Surface	*image;

	// TODO: i think the surfaces are actually the layers.
	/*
	brush = ((t_button *)elem->info)->extra;
	surfaces = elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if ((file = dir_explore("./images", DT_REG)) != NULL)
		{
			if ((image = load_image(file)) != NULL)
			{
				temp = ft_sdl_rect(0, 0, image->w, image->h);
				SDL_BlitScaled(image, NULL,
						surfaces[brush->selected_layer]->surface, &temp);
				SDL_FreeSurface(image);
			}
			else
				notify("Open_button", "Image couldnt be loaded\n");
		}
		(!file) ? notify("Open_button", "File dosent exist\n") : 0;
		ft_strdel(&file);
	}
	*/
}
