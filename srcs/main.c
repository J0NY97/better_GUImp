/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:07:25 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/03 17:04:46 by jsalmi           ###   ########.fr       */
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
		ft_putstr("1");
	tool_buttons_init(info);
		ft_putstr("2");

	slider_init(info);
	init_brush(info);
	sticker_load(info);
	drop_down_init(info);

	shape_load(info);
	shape_buttons_init(info);

	utility_init(info);

	layer_init(info);

	bui_set_window_icon(info->main, "resources/stickers/gimp-icon.png");
	/* NOTE: dont remove comment, just yank the line you want to callkk
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

void	shadow(t_bui_element *elem)
{
	t_xywh coord;

	coord = elem->position;
	if (elem->type == TYPE_ELEMENT)
	{
		SDL_FillRect(((t_bui_element *)elem->parent)->active_surface, &(SDL_Rect) {coord.x + coord.w, coord.y + 5, 5, coord.h}, 0xff9a9a9a);
		SDL_FillRect(((t_bui_element *)elem->parent)->active_surface, &(SDL_Rect) {coord.x + 5, coord.y + coord.h, coord.w, 5}, 0xff9a9a9a);
	}
	else
	{
		SDL_FillRect(((t_bui_window *)elem->parent)->active_surface, &(SDL_Rect) {coord.x + coord.w, coord.y + 5, 5, coord.h}, 0xff9a9a9a);
		SDL_FillRect(((t_bui_window *)elem->parent)->active_surface, &(SDL_Rect) {coord.x + 5, coord.y + coord.h, coord.w, 5}, 0xff9a9a9a);
	}
}
typedef	struct		s_fps
{
	float		curr;
	float		prev;
	float		avg;
	int		fps;
	int		count;
	// Delta
	float		delta_curr;
	float		delta_last;
	float		delta;
}					t_fps;

void	fps_func(t_fps *fps)
{
	fps->curr = SDL_GetTicks();
	fps->count++;
	if (fps->curr - fps->prev >= 1000)
	{
		fps->prev = fps->curr;
		fps->fps = fps->count;
		fps->count = 0;
		ft_putnbr(fps->fps);
		ft_putchar('\n');
	}
}

int					fake_main(void)
{
	t_info		*info;
	t_bui_libui	*libui;
	t_fps *fps = malloc(sizeof(t_fps));

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	libui = bui_new_libui();
	guimp_init(info, libui);
	//prefab_demo(info); //NOTE:the only reason this function was done is so that we would have prefabs in the libui.
	while (libui->run)
	{
		fps_func(fps);
		bui_event_handler_new(libui);
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

		bui_input(info->text_area);

		update_brush(info);
		update_layers(info);
		update_hidden_surface(info, libui);
		draw(libui, info);

		shadow(info->clear_workspace);

		bui_render_new(libui);
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
