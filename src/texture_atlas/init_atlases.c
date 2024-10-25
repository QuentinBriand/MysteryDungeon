/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** init_atlases
*/

#include "infos.h"
#include "atlas.h"

void create_atlases(wininf *inf)
{
    inf->atlases.atlas = sfImage_createFromFile(rootPath"/atlas.png");
    inf->atlases.pokemons_anim = load_csv(rootPath"/csv/pokemon_anims.csv");
    inf->atlases.pokemons_rect = load_csv(rootPath"/csv/pokemon_rect.csv");
    inf->atlases.houses = load_csv(rootPath"/csv/house.csv");
    inf->atlases.scenes = load_csv(rootPath"/csv/scenes.csv");
    inf->atlases.statics = load_csv(rootPath"/csv/statics.csv");
    inf->atlases.collisions = load_csv(rootPath"/csv/collisions.csv");
    inf->atlases.pnjs =
    inf->lang ? load_csv(rootPath"/csv/pnjs_fr.csv") : load_csv(rootPath"/csv/pnjs_en.csv");
    inf->atlases.icons = load_csv(rootPath"/csv/icons.csv");
    inf->atlases.menus_en = load_csv(rootPath"/csv/menus_en.csv");
    inf->atlases.menus_fr = load_csv(rootPath"/csv/menus_fr.csv");
    inf->atlases.poke_names = load_csv(rootPath"/csv/poke_names.csv");
    inf->atlases.items = load_csv(rootPath"/csv/items.csv");
    inf->atlases.item_sprites = load_csv(rootPath"/csv/items_sprite.csv");
}
