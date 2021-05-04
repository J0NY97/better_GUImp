/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:36 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 14:26:09 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	save_image(SDL_Surface *img, char *file)
{
	char *real;

	if (!(ft_strendswith(file, ".png")))
		IMG_SavePNG(img, file);
	else if (!(ft_strendswith(file, ".jpg")))
		IMG_SaveJPG(img, file, 32);
	else if (!(ft_strendswith(file, ".bmp")))
		SDL_SaveBMP(img, file);
	else
	{
		real = ft_strjoin(file, ".bmp");
		SDL_SaveBMP(img, real);
		ft_strdel(&real);
	}
	ft_printf("File saved as %s\n", file);
}

/*
void	save_img(SDL_Event e, t_bui_element *elem)
{
	char		*file;
	SDL_Surface	*pic;

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
}
	*/
