/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:52 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 12:46:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	text_to_screen(SDL_Surface *surface, t_shapes l,
		char *str, char *font_dir)
{
	SDL_Rect	temp;
	SDL_Surface *surf;
	TTF_Font	*font;

	font = TTF_OpenFont(font_dir, l.size);
	surf = TTF_RenderText_Blended(font, str, (SDL_Color) {25, 25, 25, 25 });
								// TODO : hex_to_rgba(l.color));
	temp.w = surf->w;
	temp.h = surf->h;
	temp.x = l.x1 - (temp.w / 2);
	temp.y = l.y1 - (temp.h / 2);
	SDL_BlitSurface(surf, NULL, surface, &temp);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}
