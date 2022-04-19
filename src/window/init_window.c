/*
** EPITECH PROJECT, 2022
** main
** File description:
** Init of window
*/

#include "infos.h"
#include "inputs.h"

wininf create_window_infos(int ac, char **av)
{
    srand(time(0));
    wininf inf;
    inf.settings = init_settings();
    inf.net = init_network();
    get_settings_flags(ac, av, &inf);
    inf.mode = (sfVideoMode){1920, 1080, 32};
    inf.win = sfRenderWindow_create(inf.mode, WINDOW_NAME, sfClose, NULL);
    inf.c_scene = INTRO;
    inf.interacting = 0;
    init_times(&inf);
    create_atlases(&inf);
    init_inputs(&inf);
    inf.scenes[0] = create_home(&inf, inf.settings->house);
    inf.scenes[1] = create_static_env(&inf, 0);
    inf.scenes[3] = create_static_env(&inf, 6);
    inf.scenes[4] = create_static_env(&inf, 2);
    inf.scenes[5] = create_static_env(&inf, 4);
    inf.scenes[2] = create_static_env(&inf, 6 + inf.settings->house * 2);
    inf.camera = init_camera(inf);
    create_triggers(&inf);
    inf.transition = 0;
    inf.change_scene = 0;
    inf.transi = sfRectangleShape_create();
    sfRectangleShape_setSize(inf.transi, (sfVector2f){inf.mode.width,
        inf.mode.height});
    sfRectangleShape_setFillColor(inf.transi,
        sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOrigin(inf.transi,
    (sfVector2f){inf.mode.width / 2.0f, inf.mode.height / 2.0f});
    init_textbox(&inf);
    inf.menu_padding = 40;
    inf.main_menu = init_all_menus(&inf, 0, 1);
    init_main_menu_pointers(&inf);
    inf.load_menu = init_all_menus(&inf, 1, 0);
    init_load_pointers(&inf);
    inf.c_menu = NONE;
    inf.current_menu = inf.main_menu;
    inf.net->timeout.microseconds = 5000;
    inf.intro = NULL;
    inf.ditto = NULL;
    inf.dream = NULL;
    return inf;
}
