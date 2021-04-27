/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:36 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 13:49:49 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	save_img(SDL_Event e, t_bui_element *elem)
{
	char		*file;
	SDL_Surface	*pic;

	/*
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		pic = elem->active_surface; /// TODO ((t_element *)elem->extra_info)->surface;
		if ((file = input_popup(100, 100)) == NULL)
		{
			notify("save_img", "You decided not to save the image..");
			return ;
		}
		if (!(save_image(pic, file)))
			notify("save_img", "Image couldnt be saved.");
		free(file);
	}
	*/
}
