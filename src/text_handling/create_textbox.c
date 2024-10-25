/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** create_textbox
*/

#include "rpg.h"

void init_textbox(wininf *win)
{
    sfIntRect r = (sfIntRect) {1232, 812, 224, 40};
    win->ui.background = atlas_to_sprite(r, win->atlases.atlas);
    sfVector2f mid = (sfVector2f) {r.width / 2, r.height / 2};
    sfSprite_setOrigin(win->ui.background, mid);
    win->ui.font = sfFont_createFromFile(rootPath"/fontt.ttf");
    win->ui.dialog = 0;
    win->ui.text_delay = 0.05f;
    load_alphabet(win->ui.font, FONT_SIZE);
}

int is_valid_dline(char *l, dline_parsing *p)
{
    return l[p->r2.left] != '\0' && l[p->r2.left] != '\n';
}

dline *load_line(char *l, int size, wininf *inf, void *(ptr)(size_t t))
{
    sfFont *f = inf->ui.font; char prev = 0;
    dline_parsing *p = create_dline_help(f, l);
    sfImage *font_alpha = sfTexture_copyToImage(sfFont_getTexture(f, size));
    int *steps = ptr(sizeof(int) * (p->r.left + 1));
    for (; is_valid_dline(l, p); p->r2.left++, p->r2.top++) {
        if (l[p->r2.left] == '<' && treat_parsing_balise(l, p, inf, steps))
            continue;
        if (l[p->r2.left] == '\\' && l[p->r2.left + 1] == 'n') {
            p->r2.left += 1; p->r2.width = 0; p->r2.height += p->r.height;
            p->r2.top--;
            continue;
        }
        treat_letter_dialog(inf, l, p, font_alpha);
        if (prev)
            p->r2.width -= sfFont_getKerning(f, prev, l[p->r2.left], size);
        prev = l[p->r2.left]; steps[p->r2.top] = p->r2.width;
    } sfImage_destroy(font_alpha);
    return create_lstruct((dl_creat){p->img, steps, ptr}, p->r, p->r2.top);
}

void update_rects_dialog(wininf *win)
{
    dline *c_line = (dline*)win->ui.dialog->data;
    if (c_line->i == c_line->max) {
        win->ui.dialog = win->ui.dialog->next;
        win->interacting = !win->ui.dialog ? 0 : win->interacting;
    } else {
        c_line->i = c_line->max - 1; c_line->cline = c_line->nblines - 1;
        for (int i = 0; i < c_line->nblines; i++) {
            sfSprite *sp = c_line->sps[i];
            sfTexture *t = (sfTexture *)sfSprite_getTexture(sp);
            sfVector2u si = sfTexture_getSize(t);
            sfSprite_setTextureRect(sp, (sfIntRect){0, c_line->height * i,
            si.x, c_line->height});
        }
    }
}

dline *create_lstruct(dl_creat dlcreator, sfIntRect r, int li)
{
    dline *nl = dlcreator.ptr(sizeof(dline));
    nl->img = sfTexture_createFromImage(dlcreator.img, NULL);
    nl->cline = 0;
    nl->sps = dlcreator.ptr(sizeof(sfSprite *) * r.top);
    for (int i = 0; i < r.top; i++) {
        nl->sps[i] = sfSprite_create();
        sfSprite *sp = nl->sps[i];
        float ch = r.height * i;
        sfSprite_setTexture(sp, nl->img, sfFalse);
        sfSprite_setTextureRect(sp, (sfIntRect){0, ch, 0, r.height});
    }
    nl->nblines = r.top; nl->steps = dlcreator.steps;
    nl->max = li - 1;
    nl->height = r.height;
    nl->i = 1;
    nl->time = 0;
    sfImage_destroy(dlcreator.img);
    return nl;
}
