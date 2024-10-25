/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** treat_dialog
*/

#include "rpg.h"

int treat_parsing_balise(char *line, dline_parsing *p, wininf *inf, int *steps)
{
    int y = 0;
    for (; line[p->r2.left + y] != '>'; y++);
    char *test = malloc((y + 1) * sizeof(char));
    my_strncpy(test, line + p->r2.left + 1, y - 1);
    test[y - 1] = '\0';
    int res = treat_balise(test, &p->current_color, inf);
    p->r2.left = p->r2.left + y;
    if (!res) {
        p->r2.top = p->r2.top - 1;
    } else {
        sfIntRect r = find_icons(inf, 2 + test);
        sfVector2i pos = (sfVector2i){p->r2.width - 1, p->r2.height + 1};
        add_icon(pos, p->img, r, inf->atlases.atlas);
        p->r2.width = p->r2.width + res;
        steps[p->r2.top] = p->r2.width;
    }
    free(test);
    return 1;
}

void treat_letter_dialog(wininf *inf, char *l, dline_parsing *p, sfImage *font)
{
    sfGlyph glyph = sfFont_getGlyph(inf->ui.font, l[p->r2.left],
    FONT_SIZE, sfFalse, 0.0f);
    int startY = (p->r.height - 1) + glyph.bounds.top + p->r2.height;
    for (int y = 0; y < glyph.textureRect.height; y++) {
        for (int x = 0; x < glyph.textureRect.width; x++) {
            int gx = glyph.textureRect.left + x;
            int gy = glyph.textureRect.top + y;
            sfColor c = sfImage_getPixel(font, gx, gy);
            c = sfColor_modulate(c, p->current_color);
            sfImage_setPixel(p->img, x + p->r2.width, y + startY, c);
        }
    }
    p->r2.width += (int)glyph.advance;
}
