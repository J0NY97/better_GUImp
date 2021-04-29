/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:57:52 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/29 15:10:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	text_to_screen(SDL_Surface *surface, t_shapes l,
		char *str, char *font_dir)
{
	SDL_Rect	temp;
	SDL_Surface *surf;
	TTF_Font	*font;
	t_rgba color;

	color = hex_to_rgba(l.color);
	font = TTF_OpenFont(font_dir, l.size);
	surf = TTF_RenderText_Blended(font, str, (SDL_Color) {color.r, color.g, color.b, color.a});
	temp.w = surf->w;
	temp.h = surf->h;
	temp.x = l.x1 - (temp.w / 2);
	temp.y = l.y1 - (temp.h / 2);
	SDL_BlitSurface(surf, NULL, surface, &temp);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}
