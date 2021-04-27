/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:07:25 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/27 16:15:44 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	prefab_demo(t_info *info)
{
	t_bui_element	*menu;

	// TODO: this is the bar of buttons on the bottom left, it had quit save and stuff liek that.
	/*
	menu = prefab_tools_init(info->toolbox->window,
							info->toolbox->window->surface->w - 175,
							info->toolbox->window->surface->h - 125);
							*/
}

static inline void	guimp_init(t_info *info, t_bui_libui *libui)
{
	window_init(libui, info);
	menu_init(info);

	tooltips_load(info);
	tool_buttons_init(info);

	slider_init(info);
	init_brush(info);
	layer_init(info);
	sticker_load(info);
	drop_down_init(info);

	/* NOTE: dont remove comment, just yank the line you want to call
	init_brush(info);
	tooltips_load(info);
	shape_load(info);
	menu_init(info);
	tool_buttons_init(info);
	shape_buttons_init(info);
	slider_init(info);
	drop_down_init(info);
	layer_init(info);
	utility_init(info);
	sticker_load(info);
	// TODO: i think niklas made this, so he has to make this again.
	ft_set_icon(info->main->window->win,
			"resources/stickers/gimp-icon.png");
	info->layer_amount = 1;
	*/
}

int					fake_main(void)
{
	t_info		*info;
	t_bui_libui	*libui;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	libui = bui_new_libui();
	guimp_init(info, libui);
	//prefab_demo(info);
	while (libui->run)
	{
		bui_render_the_event(libui);
		/*
		drag_drop(info, libui);
		update_brush(info);
		update_layers(info);
		update_hidden_surface(info, libui);
		*/

		// NEW
		preset_slider_events(info->r_slider);
		preset_slider_events(info->g_slider);
		preset_slider_events(info->b_slider);
		preset_slider_events(info->a_slider);
		preset_slider_events(info->size_slider);

		preset_dropdown_events(info->drop_down);
		preset_dropdown_events(info->font_down);

		update_brush(info);
	}
	//guimp_quit(info);
	//bui_libui_quit(libui);
	return (0);
}

int					main(void)
{
	fake_main();
	ft_printf("bye!");
	//while (1);
	return (0);
}
