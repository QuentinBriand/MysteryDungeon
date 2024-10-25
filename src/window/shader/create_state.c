/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_state
*/

#include "rpg.h"

sfRenderStates create_shiny_test(void)
{
    sfRenderStates state;
    state.blendMode = sfBlendAlpha;
    state.shader = my_shader_from_file(0, 0, rootPath"/src/window/shader/shiny.glsl");
    state.transform = sfTransform_Identity;
    state.texture = 0;
    return state;
}
