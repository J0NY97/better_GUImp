/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:01:56 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/28 14:08:55 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	add_new_layer_event(SDL_Event e, t_bui_element *elem)
{
	t_xywh		coords;
	int			*layer_amount;

	int a = 5;
	layer_amount = &a; // TODO: elem->extra_info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (*layer_amount == 5)
		{
			ft_putstr("Maximum layers created.");
			return ;
		}
		*layer_amount += 1;
		ft_printf("Layer_amount %d\n", *layer_amount);
	}
}
