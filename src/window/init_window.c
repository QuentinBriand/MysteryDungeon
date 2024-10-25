/*
** EPITECH PROJECT, 2022
** main
** File description:
** Init of window
*/

#include "infos.h"
#include "music.h"
#include "inputs.h"
#include "sounds.h"
#include "rpg.h"

void init_key_list(wininf *inf)
{
    const char *list[102] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9", "Escape", "LControl", "LShift", "LAlt",
    "LSystem", "RControl", "RShift", "RAlt", "RSystem", "Menu", "LBracket",
    "RBracket", "SemiColon", "Comma", "Period", "Quote", "Slash", "BackSlash",
    "Tilde", "Equal", "Hyphen", "Space", "Enter", "BackSpace", "Tab", "PageUp",
    "PageDown", "End", "Home", "Insert", "Delete", "Add", "Subtract",
    "Multiply", "Divide", "Arrow Left", "Arrow Right", "Arrow Up",
    "Arrow Down", "Numpad 0", "Numpad 1",
    "Numpad 2", "Numpad 3", "Numpad 4", "Numpad 5", "Numpad 6", "Numpad 7",
    "Numpad 8", "Numpad 9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8",
    "F9", "F10", "F11", "F12", "F13", "F14", "F15", "Pause"};
    inf->key_list = my_malloc(sizeof(char *) * 102);
    for (int i = 0; i < 101; i++)
        inf->key_list[i] = my_strdup((char *)list[i], my_malloc);
}

void init_fps(wininf *inf)
{
    sfRenderWindow_setFramerateLimit(inf->win, inf->settings->c_fps < 5 ?
    my_atoi(inf->settings->fps[inf->settings->c_fps]) : 0);
    sfText_setString(
    ((choices *)inf->options_menu->choices->prev->prev->prev->data)->choice
    , inf->settings->fps[inf->settings->c_fps]);
    sfIntRect r; r.top = 0; r.left = 0;
    sfVector2f old_pos = sfSprite_getPosition(((choices *)inf->ig_options_menu
    ->choices->prev->prev->data)->choice);
    inf->ig_choices[2] = load_line(inf->settings->fps[inf->settings->c_fps],
    FONT_SIZE, inf, my_malloc);
    r.width = inf->ig_choices[2]->steps[inf->ig_choices[2]->max], r.height =
    inf->ig_choices[2]->height;
    sfSprite_setTextureRect(inf->ig_choices[2]->sps[0], r);
    sfSprite_destroy(((choices *)inf->ig_options_menu->choices->prev->prev
    ->data)->choice);
    ((choices *)inf->ig_options_menu->choices->prev->prev->data)->choice =
    inf->ig_choices[2]->sps[0];
    sfSprite_setPosition(((choices *)inf->ig_options_menu->choices->prev->prev
    ->data)->choice, old_pos);
}

wininf create_window_infos(int ac, char **av)
{
    srand(time(0)); wininf inf; inf.lang = ENGLISH;
    inf.settings = init_settings(); inf.net = init_network();
//    // get_settings_flags(ac, av, &inf);
    inf.mode = (sfVideoMode){1920, 1080, 32};
    sfContextSettings settings = {
        .depthBits = 24,
        .stencilBits = 8,
        .antialiasingLevel = 4,
        .majorVersion = 4,
        .minorVersion = 0,
    };
    inf.win = sfRenderWindow_create(inf.mode, WINDOW_NAME, sfClose, &settings);
    
    sfRenderWindow_setPosition(inf.win, (sfVector2i) {0, 0});
    first_fill_window(&inf); inf.change_scene = 0;
    dungeon d; d.in = 0; d.enemies = 0; d.floor = 1; d.ended = 0;
    d.next = 0; d.time = 0.0f; d.inf = 0; inf.dungeon = d;
    inf.transi = my_rectangle();
    sfRectangleShape_setSize(inf.transi, (sfVector2f){inf.mode.width,
        inf.mode.height});
    sfRectangleShape_setFillColor(inf.transi,
        sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOrigin(inf.transi,
    (sfVector2f){inf.mode.width / 2.0f, inf.mode.height / 2.0f});
    init_textbox(&inf); init_hud(&inf);
    inf.main_menu = init_all_menus(&inf, MAIN_IDX, 1);
    mid_fill_window(&inf); last_fill_window(&inf);
    return inf;
}
